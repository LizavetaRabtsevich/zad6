#include "rect.h"

Rect::Rect() {}

Rect::Rect(QPoint s, QPoint e) {
    rect = QRect(s, e).normalized();
}

void Rect::draw(QPainter &painter) {
    painter.drawRect(rect);
}

void Rect::serialize(QDataStream &out) {
    out << rect;
}

void Rect::deserialize(QDataStream &in) {
    in >> rect;
}
