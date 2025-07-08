#pragma once

#include "shape.h"
#include <QRect>

class Rect : public Shape {
public:
    QRect rect;
    Rect();
    Rect(QPoint s, QPoint e);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};
