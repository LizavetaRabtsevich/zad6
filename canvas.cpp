#include "canvas.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "triangle.h"
#include <QMouseEvent>
#include <QPainter>
#include <QFile>
#include <QDataStream>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
}

Canvas::~Canvas() {
    qDeleteAll(shapes);
}

void Canvas::setMode(Mode m) {
    mode = m;
}

void Canvas::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    for (Shape *shape : shapes) {
        shape->draw(painter);
    }
    if (currentShape) {
        currentShape->draw(painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    startPoint = event->pos();
    if (mode == DrawLine) {
        currentShape = new Line(startPoint, startPoint);
    } else if (mode == DrawRect) {
        currentShape = new Rect(startPoint, startPoint);
    } else if (mode == DrawCircle) {
        currentShape = new Circle(startPoint , 0);
    } else if (mode == DrawTriangle) {
        currentShape = new Triangle(startPoint, startPoint, startPoint);
    }
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (!currentShape)
        return;
    if (mode == DrawLine) {
        dynamic_cast<Line *>(currentShape)->end = event->pos();
    } else if (mode == DrawRect) {
        dynamic_cast<Rect *>(currentShape)->rect = QRect(startPoint, event->pos()).normalized();
    } else if (mode == DrawCircle) {
        auto circle = dynamic_cast<Circle *>(currentShape);
        if (circle) {
            int r = std::hypot(event->pos().x() - startPoint.x(), event->pos().y() - startPoint.y());
            circle->radius = r;
        }
    } else if (mode == DrawTriangle) {
        auto triangle = dynamic_cast<Triangle *>(currentShape);
        if (triangle) {
            QPoint p2 = event->pos();
            QPoint p3((startPoint.x() + p2.x()) / 2, startPoint.y() - std::abs(p2.x() - startPoint.x()));
            triangle->p2 = p2;
            triangle->p3 = p3;
        }
    }
    update();
}


void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (!currentShape)
        return;
    if (mode == DrawLine) {
        auto line = dynamic_cast<Line *>(currentShape);
        if (line)
            line->end = event->pos();
    } else if (mode == DrawRect) {
        auto rect = dynamic_cast<Rect *>(currentShape);
        if (rect)
            rect->rect = QRect(startPoint, event->pos()).normalized();
    } else if (mode == DrawCircle) {
        auto circle = dynamic_cast<Circle *>(currentShape);
        if (circle) {
            int r = std::hypot(event->pos().x() - startPoint.x(), event->pos().y() - startPoint.y());
            circle->radius = r;
        }
    } else if (mode == DrawTriangle) {
        auto triangle = dynamic_cast<Triangle *>(currentShape);
        if (triangle) {
            QPoint p2 = event->pos();
            QPoint p3((startPoint.x() + p2.x()) / 2, startPoint.y() - std::abs(p2.x() - startPoint.x()));
            triangle->p2 = p2;
            triangle->p3 = p3;
        }
    }

    shapes.append(currentShape);
    currentShape = nullptr;
    update();
}


void Canvas::clearShapes() {
    qDeleteAll(shapes);
    shapes.clear();
    update();
}

void Canvas::saveToFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) return;

    QDataStream out(&file);
    out << shapes.size();
    for (Shape *shape : shapes) {
        if (dynamic_cast<Line *>(shape)) {
            out << QString("Line");
            shape->serialize(out);
        } else if (dynamic_cast<Rect *>(shape)) {
            out << QString("Rect");
            shape->serialize(out);
        }
    }
}

void Canvas::loadFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) return;

    clearShapes();

    QDataStream in(&file);
    int count;
    in >> count;
    for (int i = 0; i < count; ++i) {
        QString type;
        in >> type;
        Shape *shape = nullptr;
        if (type == "Line") {
            shape = new Line();
        } else if (type == "Rect") {
            shape = new Rect();
        }
        if (shape) {
            shape->deserialize(in);
            shapes.append(shape);
        }
    }
    update();
}
