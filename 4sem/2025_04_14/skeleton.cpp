#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
skeleton::skeleton(QWidget* parent):QMainWindow(parent)
{
    QPixmap newpic("../../assets/new.png");
    QPixmap openpic("../../assets/open.png");
    QPixmap quitpic("../../assets/quit.png");
    QAction* quit = new QAction("&Quit", this);
    QMenuBar* file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    QToolBar* toolbar = addToolbar("Menu");
    toolbar->addAction(QIcon(newpic), "New");
    toolbar->addAction(QIcon(openpic), "Open");
    toolbar->addSeparator();
    QAction* quit2 = toolbar->addAction(QIcon(quitpic), "quit");
    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);
    QTextEdit* edit = new QTextEdit(this);
    setCe
    statusBar()->showMessage("Ready");

}
