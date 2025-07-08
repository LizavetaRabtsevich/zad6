#pragma once

#include <QPainter>
#include <QDataStream>

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw(QPainter &painter) = 0;
    virtual void serialize(QDataStream &out) = 0;
    virtual void deserialize(QDataStream &in) = 0;
};
