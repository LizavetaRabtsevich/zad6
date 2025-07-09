#pragma once

#include "shape.h"
#include <QPoint>

class Circle : public Shape {
public:
    QPoint center;
    int radius;

    Circle();
    Circle(QPoint c, int r);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;  
};
