#include "mainwindow.h"
#include <QApplication>
#include <boost/config.hpp>
#include <iostream>                         // for std::cout
#include <utility>                          // for std::pair
#include <algorithm>                        // for std::for_each
#include <boost/utility.hpp>                // for boost::tie
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include "circleWidget.h"


using namespace boost;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.drawGraph();
    /////////////////////

 /*   CircleWidget cw(5);
        cw.resize(60,60);
        cw.show();
*/
    return a.exec();
}
