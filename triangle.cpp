#include "triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(QPoint a, QPoint b, QPoint c) : p1(a), p2(b), p3(c) {}

void Triangle::draw(QPainter &painter) {
    painter.setPen(QPen(color, 2));
    QPolygon polygon;
    polygon << p1 << p2 << p3;
    painter.drawPolygon(polygon);
}

void Triangle::serialize(QDataStream &out) {
    out << p1 << p2 << p3 << color;
}

void Triangle::deserialize(QDataStream &in) {
    in >> p1 >> p2 >> p3 >> color;
}

