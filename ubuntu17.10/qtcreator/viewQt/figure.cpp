#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    // Set starting coordinate to draw shapes
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    /* Connect the signal change of coordinates to a slot running the update contents of the object.
     * The signal and slot are present in the base class
     * */
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    /* Return the area in which lies the figure.
     * Upgradable region depends on the starting point and drawing from the endpoint
     * */
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()
{
    // Call update area in which the figure lies
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}
