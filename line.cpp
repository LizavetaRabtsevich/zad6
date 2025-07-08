#include "line.h"

Line::Line() {}

Line::Line(QPoint s, QPoint e) : start(s), end(e) {}

void Line::draw(QPainter &painter) {
    painter.drawLine(start, end);
}

void Line::serialize(QDataStream &out) {
    out << start << end;
}

void Line::deserialize(QDataStream &in) {
    in >> start >> end;
}
