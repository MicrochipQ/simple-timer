#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void setupUi();

    void ShowContextMenu(const QPoint &);
    void SwitchToTimer();
    void SwitchToStopwatch();
};
