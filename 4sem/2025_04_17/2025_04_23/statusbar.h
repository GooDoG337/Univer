#pragma once
#include <QMainWindow>
#include <QPushButton>
class Statusbar:public QMainWindow
{
    Q_OBJECT
public:
    Statusbar(QWidget* parent = nullptr);
private slots:
    void onOkPressed();
    void onApplyPressed();
private:
    QPushButton* okBtn;
    QPushButton* applyBtn;
};
