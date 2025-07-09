#pragma once

#include <QPainter>
#include <QDataStream>

class Shape {
public:
    QColor color = Qt::black;
    virtual ~Shape() {}
    virtual void draw(QPainter &painter) = 0;
    virtual void serialize(QDataStream &out) = 0;
    virtual void deserialize(QDataStream &in) = 0;
};
