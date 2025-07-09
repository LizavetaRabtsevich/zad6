#include "rect.h"

Rect::Rect() {}

Rect::Rect(QPoint s, QPoint e) {
    rect = QRect(s, e).normalized();
}

void Rect::draw(QPainter &painter) {
    painter.setPen(QPen(color, 2));
    painter.drawRect(rect);
}

void Rect::serialize(QDataStream &out) {
    out << rect << color;
}

void Rect::deserialize(QDataStream &in) {
    in >> rect >> color;
}

