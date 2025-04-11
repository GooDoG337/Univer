#include "mainwindow.h"
#include "anothermenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    anothermenu w;
    w.show();
    return a.exec();
}
