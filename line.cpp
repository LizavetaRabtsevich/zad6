#include "line.h"

Line::Line() {}

Line::Line(QPoint s, QPoint e) : start(s), end(e) {}

void Line::draw(QPainter &painter) {
    painter.setPen(QPen(color, penWidth));
    painter.drawLine(start, end);
}

void Line::serialize(QDataStream &out) {
    out << start << end << color << penWidth;
}

void Line::deserialize(QDataStream &in) {
    in >> start >> end >> color >> penWidth;
}

