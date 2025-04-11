#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QPushButton>
#include "plusminus.h"
class Cursors:public QWidget {
public:
    Cursors(QWidget *parent = 0);
};

Cursors::Cursors(QWidget *parent):
    QWidget(parent) {
    QFrame* frame1 = new QFrame(this);
    frame1->setFrameStyle(QFrame::Box);
    frame1->setCursor(Qt::SizeAllCursor);
    QFrame* frame2 = new QFrame(this);
    frame2->setFrameStyle(QFrame::Box);
    frame2->setCursor(Qt::WaitCursor);
    QFrame* frame3 = new QFrame(this);
    frame3->setFrameStyle(QFrame::Box);
    frame3->setCursor(Qt::PointingHandCursor);
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(frame1,0,0);
    grid->addWidget(frame2,0,1);
    grid->addWidget(frame3,0,2);
    setLayout(grid);
}

class MyButton:public QWidget {
public:
    MyButton(QWidget *parrent = 0);
};
MyButton::MyButton(QWidget *parrent):
    QWidget(parrent){
    QPushButton *quitBtn = new QPushButton(QString("Release HL:EP3"), this);
    quitBtn->setGeometry(50,40,150,60);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QWidget window;
    //Cursors window;
    //MyButton window;
    plusminus window;
    window.resize(256,256);
    window.move(300,300);
    window.setWindowTitle("Windows11");
    window.setToolTip("Who?");
    window.setWindowIcon(QIcon("/home/stud-8/Downloads/company_logo_563411.png"));

    window.show();
    return a.exec();
}
