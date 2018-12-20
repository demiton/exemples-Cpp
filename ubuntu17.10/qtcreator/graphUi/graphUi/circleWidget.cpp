#include "circleWidget.h"

CircleWidget:: CircleWidget(int number) : _number(number), _fill(false) {/*empty*/}

void CircleWidget::paintEvent(QPaintEvent * e){
      e->accept();

      QPainter p(this);

      QRect r = rect();
      p.setPen(Qt::black);
      if (_fill) p.setBrush(Qt::green);
      p.drawEllipse(r);

      p.drawText(r, Qt::AlignCenter, QString("%1").arg(_number));
}

void CircleWidget::mousePressEvent(QMouseEvent * e){
      _fill = !_fill;
      update();  // this will induce another call to paintEvent() ASAP
      e->accept();
}

