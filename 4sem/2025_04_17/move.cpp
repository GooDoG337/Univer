#include "move.h"
#include <QMoveEvent>
move::move(QWidget *parent):QWidget(parent) {};
void move::moveEvent(QMoveEvent *e) {
    int x = e->pos().x();
    int y = e->pos().y();
    QString text = QString::number(x) + " " + QString::number(y);
    setWindowTitle(text);
}
