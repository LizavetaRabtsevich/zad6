#pragma once

#include <QWidget>
#include <QVector>
#include "shape.h"

class Canvas : public QWidget {
    Q_OBJECT
public:
    enum Mode { None, DrawLine, DrawRect, DrawCircle, DrawTriangle };
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void setMode(Mode m);
    void saveToFile(const QString &fileName);
    void loadFromFile(const QString &fileName);
    void setCurrentColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;

private:
    QVector<Shape *> shapes;
    Shape *currentShape = nullptr;
    Mode mode = None;
    QPoint startPoint;
    QColor currentColor = Qt::black;
    void clearShapes();
};
