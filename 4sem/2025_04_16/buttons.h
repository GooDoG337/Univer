#pragma once
#include <QWidget>
#include <QPushButton>
class buttons:public QWidget {
public:
    buttons(QWidget* parent = nullptr);
private:
    QPushButton* okBtn;
    QPushButton* applyBtn;
};
