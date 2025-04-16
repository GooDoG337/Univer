#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>
#include <QWidget>
//#include "vertical.h"
//#include "buttons.h"
//#include "nesting.h"
//#include "form.h"
//#include "calculatr.h"
#include "review.h"
/*class Absolute:public QWidget {
public:
    Absolute(QWidget* parent = nullptr);
};

Absolute::Absolute(QWidget *parent):QWidget(parent) {
    auto* tedit = new QTextEdit(this);
    tedit->setGeometry(5,5,200,150);
}*/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    review window;
    window.setWindowTitle("Absolute");
    window.resize(400,400);
    window.show();
    return a.exec();
}
