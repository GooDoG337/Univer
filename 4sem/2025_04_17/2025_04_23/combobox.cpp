#include "combobox.h"
#include <QHBoxLayout>
ComboBoxEx::ComboBoxEx(QWidget* parent):QWidget(parent) {
    QStringList faculties = {"Doom", "Oblivion", "Mafia", "Forza", "NFS", "Something"};
    auto* hbox = new QHBoxLayout(this);
    combo = new QComboBox;
    combo->addItems(faculties);
    hbox->addWidget(combo);
    hbox->addSpacing(15);
    label = new QLabel("Text", this);
    hbox->addWidget(label);
    connect(combo, qOverload<const QString&>(&QComboBox::activated),
           label, &QLabel::setText);
}
