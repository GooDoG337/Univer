#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.resize(250,150);
    window.setWindowTitle("Half-Life 2: Episode 3");
    window.show();
    return app.exec();
}
