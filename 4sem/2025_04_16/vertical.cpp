#include "vertical.h"
#include <QVBoxLayout>
#include <QPushButton>
VerticalBox::VerticalBox(QWidget *parent):QWidget(parent) {
    auto* vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);
    auto* prikmat = new QPushButton("Prikmat", this);
    auto* notprikmat = new QPushButton("NotPrikmat", this);
    auto* arab = new QPushButton("Arab", this);
    auto* indus = new QPushButton("Indus", this);
    auto* ivan = new QPushButton("Ivan", this);
    auto* rando = new QPushButton("Random", this);

    prikmat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    notprikmat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    arab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    indus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ivan->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rando->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbox->addWidget(prikmat);
    vbox->addWidget(notprikmat);
    vbox->addWidget(arab);
    vbox->addWidget(indus);
    vbox->addWidget(ivan);
    vbox->addWidget(rando);

}
