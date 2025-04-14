#include "check.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

Checkmem::Checkmem(QWidget* parent):QMainWindow(parent) {
    viewst = new QAction("&View statusbar", this);
    viewst->setCheckable(true);
    viewst->setChecked(true);
    QMenu *file;
    file = menuBar() -> addMenu("&File");
    file -> addAction(viewst);
    statusBar();
    connect(viewst, &QAction::triggered, this, &Checkmem::toggleStatusBar);
}
void Checkmem::toggleStatusBar()
{
    if(viewst->isChecked())
    {
        statusBar()->show();
    } else {
        statusBar()->hide();
    }
}
