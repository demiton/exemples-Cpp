#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    // The property is the starting point, which draw the shape
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)
    // The property is the endpoint, which draw the shape
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

signals:
    void pointChanged();

private:
    QPointF m_startPoint;
    QPointF m_endPoint;

    QRectF boundingRect() const;

public slots:
    void updateRomb();
};

#endif // FIGURE_H
