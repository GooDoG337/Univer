#pragma once
#include <QWidget>

class keypress:public QWidget {
public:
    keypress(QWidget* parent = 0);
protected:
    void keyPressEvent(QKeyEvent* e);
};
