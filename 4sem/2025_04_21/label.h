#pragma once
#include <QWidget>
#include <QLabel>
class label:public QWidget
{
public:
    label(QWidget* parent = nullptr);
private:
    QLabel* laabel;
};

