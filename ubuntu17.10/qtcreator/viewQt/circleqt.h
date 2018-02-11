#ifndef CIRCLEQT_H
#define CIRCLEQT_H
#include "circle.h"
#include <QObject>
extern Circle Ci; // inutile ici, uniquement dans dialog
class CircleQt
{
public:
    CircleQt();
    CircleQt(Circle *Ci);
};

#endif // CIRCLEQT_H
