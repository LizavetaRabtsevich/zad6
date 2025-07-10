#pragma once

#include "shape.h"
#include <QVector>
#include <QPoint>

class FreeLine : public Shape {
public:
    QVector<QPoint> points;

    FreeLine();
    void addPoint(const QPoint &point);

    void draw(QPainter &painter) override;
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;
};
