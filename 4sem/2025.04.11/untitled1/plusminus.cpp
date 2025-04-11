#include "plusminus.h"
#include <QGridLayout>
plusminus::plusminus(QWidget* parent):QWidget(parent) {
    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *minBtn = new QPushButton("-", this);
    lbl = new QLabel("0", this);
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plsBtn,0,0);
    grid->addWidget(minBtn,0,1);
    grid->addWidget(lbl,1,1);
    setLayout(grid);
    connect(plsBtn, &QPushButton::clicked, this, &plusminus::onPlus);
    connect(minBtn, &QPushButton::clicked, this, &plusminus::onMinus);
}
void plusminus::onPlus() {
    int val = lbl->text().toInt();
    val++;
    lbl->setText(QString::number(val));
}
void plusminus::onMinus() {
    int val = lbl->text().toInt();
    val--;
    lbl->setText(QString::number(val));
}
