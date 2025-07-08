#pragma once

#include "shape.h"
#include <QPoint>

class Line : public Shape {
public:
    QPoint start, end;
    Line();
    Line(QPoint s, QPoint e);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};
