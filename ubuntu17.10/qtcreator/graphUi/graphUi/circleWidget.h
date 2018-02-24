#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

class CircleWidget : public QWidget
{
public:
   CircleWidget(int);
   virtual void paintEvent(QPaintEvent *);
   virtual void mousePressEvent(QMouseEvent *);
private:
   const int _number;
   bool _fill;
};


#endif // CIRCLE_H
