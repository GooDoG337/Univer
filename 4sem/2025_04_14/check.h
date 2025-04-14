#pragma once
#include <QMainWindow>
#include <QApplication>

class Checkmem:public QMainWindow {
    Q_OBJECT
public:
    Checkmem(QWidget *parent = 0);
private slots:
    void toggleStatusBar();
private:
    QAction *viewst;
};
