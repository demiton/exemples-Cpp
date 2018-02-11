#ifndef ROMB_H
#define ROMB_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Inheriting from a class Figure, which implements common functionality for all figures
 * */
class Romb : public Figure
{
    Q_OBJECT

public:
    explicit Romb(QPointF point, QObject *parent = 0);
    ~Romb();

private:
    // For Romb realize itself only drawing
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
