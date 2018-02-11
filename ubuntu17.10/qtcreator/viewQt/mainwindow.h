#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    PaintScene *scene;
    QTimer *timer;
private:
    void resizeEvent(QResizeEvent * event);
private slots:
    void slotTimer();
    void on_pushButton_clicked();       // Enable drawing Romb
    void on_pushButton_2_clicked();     // Enable drawing Square
    void on_pushButton_3_clicked();     // Enable drawing Triangle

};

#endif // MAINWINDOW_H
