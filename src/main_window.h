#pragma once

#include <QMainWindow>
#include <QSystemTrayIcon>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSystemTrayIcon *trayIcon;

    MainWindow();

private:
    void setupUi();

    void ShowContextMenu(const QPoint &);
    void SwitchToTimer();
    void SwitchToStopwatch();
};
