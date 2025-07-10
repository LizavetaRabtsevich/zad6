#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse() {}

Ellipse::Ellipse(QPoint start, QPoint end)
{
    rect = QRect(start, end).normalized();
}

void Ellipse::draw(QPainter &painter)
{
    painter.setPen(QPen(color, penWidth));
    painter.drawEllipse(rect);
}

void Ellipse::serialize(QDataStream &out)
{
    out << rect << color << penWidth;
}

void Ellipse::deserialize(QDataStream &in)
{
    in >> rect >> color >> penWidth;
}
