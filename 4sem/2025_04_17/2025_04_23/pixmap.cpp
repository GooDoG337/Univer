#include "pixmap.h"
#include <QPixmap>
#include <QHBoxLayout>
#include <QLabel>
Pixmap::Pixmap(QWidget* parent):QWidget(parent) {
    QHBoxLayout* hbox = new QHBoxLayout(this);
    QPixmap pixmap("/home/stud-8/Petrov/Doodle/assets/ladapriora.jpg");
    QLabel* lbl = new QLabel(this);
    lbl->setPixmap(pixmap);
    hbox->addWidget(lbl, 0, Qt::AlignTop);
}
