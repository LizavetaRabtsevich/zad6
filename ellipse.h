#pragma once

#include "shape.h"
#include <QRect>

class Ellipse : public Shape {
public:
    QRect rect;

    Ellipse();
    Ellipse(QPoint start, QPoint end);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};
