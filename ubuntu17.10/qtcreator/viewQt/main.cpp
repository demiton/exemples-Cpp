#include "dialog.h"
#include "circle.h"
#include <QApplication>

int ci;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    ///Ajout Circles
    Circle C1;
    C1.afficher();
    return a.exec();
}
