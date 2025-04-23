#include "statusbar.h"
#include <QLabel>
#include <QFrame>
#include <QStatusBar>
#include <QHBoxLayout>
Statusbar::Statusbar(QWidget* parent):QMainWindow(parent) {
    auto* frame = new QFrame(this);
    setCentralWidget(frame);
    auto* hbox = new QHBoxLayout(frame);
    okBtn = new QPushButton("OK", frame);
    hbox->addWidget(okBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    applyBtn = new QPushButton("Apply", frame);
    hbox->addWidget(applyBtn, 1, Qt::AlignLeft | Qt::AlignTop);
    statusBar();
    connect(okBtn, &QPushButton::clicked, this, &Statusbar::onOkPressed);
    connect(applyBtn, &QPushButton::clicked, this, &Statusbar::onApplyPressed);
}

void Statusbar::onOkPressed() {
    statusBar()->showMessage("OK Button pressed", 3000);
}
void Statusbar::onApplyPressed() {
    statusBar()->showMessage("Apply Button pressed", 3000);
}
