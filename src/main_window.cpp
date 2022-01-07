#include <QMenu>
#include "main_window.h"
#include "timer_widget.h"
#include "stopwatch_widget.h"

MainWindow::MainWindow()
{
    trayIcon = new QSystemTrayIcon(this);

    setupUi();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, this, &MainWindow::ShowContextMenu);

    SwitchToTimer();
}

void MainWindow::setupUi()
{
    setContentsMargins(20, 20, 20, 20);
}

void MainWindow::ShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);

    QAction timerAction("Timer");
    contextMenu.addAction(&timerAction);
    connect(&timerAction, &QAction::triggered, this, &MainWindow::SwitchToTimer);

    QAction stopwatchAction("Stopwatch");
    contextMenu.addAction(&stopwatchAction);
    connect(&stopwatchAction, &QAction::triggered, this, &MainWindow::SwitchToStopwatch);

    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::SwitchToTimer()
{
    TimerWidget *timerWidget = new TimerWidget(this);
    setCentralWidget(timerWidget);
}

void MainWindow::SwitchToStopwatch()
{
    StopwatchWidget *stopwatchWidget = new StopwatchWidget(this);
    setCentralWidget(stopwatchWidget);
}

void MainWindow::SendNotification(const QString &title, const QString &msg)
{
    trayIcon->show();
    trayIcon->showMessage(title, msg);
    trayIcon->hide();
}
