#pragma once
#include <QWidget>
#include <QProgressBar>
#include <QPushButton>

class ProgressBarEx:public QWidget {
    Q_OBJECT
public:
    ProgressBarEx(QWidget* parent = nullptr);
private:
    int progress;
    QTimer* timer;
    QPushButton* startBtn;
    QPushButton* stopBtn;
    QProgressBar* pbar;
    static const int DELAY = 200;
    static const int MAX_VALUE = 100;
    void updateBox();
    void startMyTimer();
    void stopMyTimer();
    void updateBar();
};
