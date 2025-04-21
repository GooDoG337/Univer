#include "slider.h"
#include <QHBoxLayout>
Slider::Slider(QWidget* parent):QWidget(parent) {
    auto* hbox = new QHBoxLayout(this);
    slider = new QSlider(Qt::Horizontal, this);
    hbox->addWidget(slider);
    label = new QLabel("0", this);
    hbox->addWidget(label);
    connect(slider, &QSlider::valueChanged, label, qOverload<int>(&QLabel::setNum));
}
