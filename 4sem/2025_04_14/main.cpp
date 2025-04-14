#include "mainwindow.h"

#include <QApplication>
//#include "check.h"
#include "skeleton.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    skeleton window;
    window.resize(256,256);
    window.move(300,300);
    window.setWindowTitle("Windows11");
    window.setToolTip("Who?");
    window.show();
    return a.exec();
}
