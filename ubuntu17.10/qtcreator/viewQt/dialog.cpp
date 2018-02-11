#include "dialog.h"

#include "ui_dialog.h"
#include <QGraphicsItem>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

   // scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(6);




    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ellipse = scene ->addEllipse(10,10,100,100,blackpen,redBrush);
    rectangle = scene ->addRect(-140,100,100,200,blackpen,blueBrush);
    rectangle->setFlag (QGraphicsItem::ItemIsMovable,true);


    //Timer

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Dialog::slotTimer);
    timer->start(100);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Dialog::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QDialog::resizeEvent(event);
}

void Dialog::on_pushButton_clicked()
{
    ui->graphicsView->rotate(-1);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(1);
}

void Dialog::on_pushButton_3_clicked()
{
scene->setTypeFigure(PaintScene::RombType);
}

void Dialog::on_pushButton_4_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
}

void Dialog::on_pushButton_5_clicked()
{
 scene->setTypeFigure(PaintScene::TriangleType);
}
