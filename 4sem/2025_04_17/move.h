#pragma once
#include <QMainWindow>
class move:public QWidget
{
    Q_OBJECT;
public:
    move(QWidget* parent = nullptr);
protected:
    void moveEvent(QMoveEvent *e);
};

