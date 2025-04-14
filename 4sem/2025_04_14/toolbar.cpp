#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

toolbar::toolbar(QWidget *parent):QMainWindow(parent) {
    QPixmap newpic("../../assets/new.png");
    QPixmap openpic("../../assets/open.png");
    QPixmap quitpic("../../assets/quit.png");
    QToolBar *toolbar = addToolBar("main");
    toolbar -> addAction(QIcon(newpic), "New File");
    toolbar -> addAction(QIcon(openpic), "Open File");
    toolbar -> addSeparator();
    QAction *quit = toolbar->addAction(QIcon(quitpic), "Quit");
    connect(quit, &QAction::triggered, qApp, &QApplication::exit);
}
