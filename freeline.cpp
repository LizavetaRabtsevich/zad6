#include "freeline.h"
#include <QPainter>

FreeLine::FreeLine() {}

void FreeLine::addPoint(const QPoint &point) {
    points.append(point);
}

void FreeLine::draw(QPainter &painter) {
    if (points.isEmpty()) return;

    painter.setPen(QPen(color, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawPolyline(points.data(), points.size());
}

void FreeLine::serialize(QDataStream &out) {
    out << points << color << penWidth;
}

void FreeLine::deserialize(QDataStream &in) {
    in >> points >> color >> penWidth;
}
