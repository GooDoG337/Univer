#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class plusminus: public QWidget {
    Q_OBJECT
public:
    plusminus(QWidget *parent = 0);
private slots:
    void onPlus();
    void onMinus();
private:
    QLabel *lbl;
};
