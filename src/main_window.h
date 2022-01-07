#pragma once

#include <QMainWindow>
#include <QSystemTrayIcon>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void SendNotification(const QString &title, const QString &msg);

private:
    QSystemTrayIcon *trayIcon;

    void setupUi();

    void ShowContextMenu(const QPoint &);
    void SwitchToTimer();
    void SwitchToStopwatch();
};
