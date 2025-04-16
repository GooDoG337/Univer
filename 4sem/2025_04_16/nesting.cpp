#include "nesting.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
Layouts::Layouts(QWidget* parent) {
    auto *vbox = new QVBoxLayout();
    auto *hbox = new QHBoxLayout(this);
    auto *lw = new QListWidget(this);
    lw->addItem("Prikmat");
    lw->addItem("Notprikmat");
    lw->addItem("Ivan");
    lw->addItem("Rando");
    lw->addItem("Arab");
    lw->addItem("Indus");
    auto* add = new QPushButton("Add", this);
    auto* rename = new QPushButton("Rename", this);
    auto* remove = new QPushButton("Remove", this);
    auto* remove_all = new QPushButton("Remove all", this);
    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(remove_all);
    vbox->addStretch(1);
    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);
    setLayout(hbox);
}
