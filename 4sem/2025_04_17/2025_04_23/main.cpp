#include "mainwindow.h"

#include <QApplication>
//#include "combobox.h"
//#include "statusbar.h"
//#include "listwidget.h"
//#include "progressbar.h"
#include "pixmap.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixmap w;
    w.show();
    return a.exec();
}
