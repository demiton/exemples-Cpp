#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::drawGraph()
{
    this->go.setGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}
