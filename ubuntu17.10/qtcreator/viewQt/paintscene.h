#ifndef PAINTSCENE_H
#define PAINTSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // The property of this type is used figures
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;                 // Return this type
    void setTypeFigure(const int type);     // Setting this type

    // Listing the types of figures
    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType
    };

signals:
    void typeFigureChanged();

private:
    /* The object for the temporary storage of the rendered shapes.
     * It is an object of the base class for all three types of figures in the example
     * */
    Figure *tempFigure;
    int m_typeFigure;

private:
    // To draw using the mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
