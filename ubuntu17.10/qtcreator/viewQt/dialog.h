#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "paintscene.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:

    void slotTimer();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
private:
    void resizeEvent(QResizeEvent * event);

private:
    Ui::Dialog *ui;
    //QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem * rectangle;

    PaintScene *scene;
    QTimer *timer;


};

#endif // DIALOG_H
