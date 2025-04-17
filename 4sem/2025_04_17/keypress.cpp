#include "keypress.h"
#include <QKeyEvent>
#include <QApplication>
keypress::keypress(QWidget* parent):QWidget(parent) {}
void keypress::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape) {
        qApp->quit();
    }
}
