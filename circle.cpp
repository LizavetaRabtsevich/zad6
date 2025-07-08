#include "circle.h"
#include <QtMath>

Circle::Circle() {}

Circle::Circle(QPoint c, int r) : center(c), radius(r) {}

void Circle::draw(QPainter &painter) {
    painter.drawEllipse(center, radius, radius);
}

void Circle::serialize(QDataStream &out) {
    out << center << radius;
}

void Circle::deserialize(QDataStream &in) {
    in >> center >> radius;
}
