#pragma once
#include <QWidget>
#include <QLabel>
class timer:public QWidget
{
public:
    timer(QWidget* parent = nullptr);
protected:
    void timerEvent(QTimerEvent* e);
private:
    QLabel* label;
};
