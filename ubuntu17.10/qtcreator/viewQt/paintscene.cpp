#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Set the final coordinates of the mouse can draw into the current figure
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Update the contents of the scene, you need to remove artifacts when drawing shapes
     * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

/* Once clicked the mouse button, create the figure of one of the three types
 * and put it on the stage, keeping a pointer to it in the variable tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        /*Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;*/
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType: {
       /* Triangle *item = new Triangle(event->scenePos());
        * addEllipse(10,10,100,100,blackpen,redBrush);
        item->setPos(event->pos());
        tempFigure = item;*/
        break;
    }
    default:{
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}
