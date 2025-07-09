#pragma once

#include "shape.h"
#include <QPoint>

class Triangle : public Shape {
public:
    QPoint p1, p2, p3;
    Triangle();
    Triangle(QPoint a, QPoint b, QPoint c);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};
