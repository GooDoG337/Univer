#include "mainwindow.h"
#include "simplemenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    simplemenu window;
    window.resize(256,256);
    window.setWindowTitle("menu");
    window.show();
    return app.exec();
}
