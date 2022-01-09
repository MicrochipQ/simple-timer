#include <QIcon>
#include <QMenu>
#include <QPixmap>
#include "main_window.h"
#include "timer_widget.h"
#include "stopwatch_widget.h"

MainWindow::MainWindow()
{
    // TODO: put a normal icon
    trayIcon = new QSystemTrayIcon(QIcon(QPixmap(32, 32)));
    trayIcon->show();

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
