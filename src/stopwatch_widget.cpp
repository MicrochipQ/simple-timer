#include <QListWidgetItem>
#include <QString>
#include "stopwatch_widget.h"

StopwatchWidget::StopwatchWidget(QWidget *parent)
    : QWidget(parent)
{
    this->parent = parent;
    timer = new QTimer(this);
    relativeTime = new QTime(0, 0, 0, 0);

    setupUi();

    connect(startButton, &QPushButton::clicked, this, &StopwatchWidget::OnStart);
    connect(pauseButton, &QPushButton::clicked, this, &StopwatchWidget::OnPause);
    connect(resetButton, &QPushButton::clicked, this, &StopwatchWidget::OnReset);
    connect(lapButton, &QPushButton::clicked, this, &StopwatchWidget::OnLap);
    connect(timer, &QTimer::timeout, this, &StopwatchWidget::OnTick);

    OnReset();
}

void StopwatchWidget::setupUi()
{
    parent->setMinimumSize(500, 300);
    parent->resize(parent->minimumSize());

    layout = new QVBoxLayout();
    controlsLayout = new QHBoxLayout();

    roundsList = new QListWidget();
    layout->addWidget(roundsList);

    resetButton = new QPushButton("Reset");
    controlsLayout->addWidget(resetButton);

    time = new QTimeEdit();
    time->setReadOnly(true);
    time->setDisplayFormat("HH:mm:ss.zzz");
    controlsLayout->addWidget(time);

    startButton = new QPushButton("Start");
    controlsLayout->addWidget(startButton);

    pauseButton = new QPushButton("Pause");
    controlsLayout->addWidget(pauseButton);

    lapButton = new QPushButton("Lap");
    controlsLayout->addWidget(lapButton);

    layout->addLayout(controlsLayout);
    setLayout(layout);
}

void StopwatchWidget::OnStart()
{
    time->show();
    startButton->hide();
    pauseButton->show();
    resetButton->show();
    lapButton->show();

    timer->start(1);
}

void StopwatchWidget::OnPause()
{
    startButton->show();
    pauseButton->hide();

    timer->stop();
}

void StopwatchWidget::OnReset()
{
    time->setTime(QTime(0, 0, 0, 0));
    relativeTime = new QTime(0, 0, 0, 0);
    roundsList->clear();

    time->hide();
    startButton->show();
    pauseButton->hide();
    resetButton->hide();
    lapButton->hide();

    timer->stop();
}

void StopwatchWidget::OnLap()
{
    roundsList->addItem(QString("%1 --- %2").arg(time->text()).arg(relativeTime->toString("HH:mm:ss.zzz")));
    roundsList->scrollToBottom();
    relativeTime = new QTime(0, 0, 0, 0);
}

void StopwatchWidget::OnTick()
{
    time->setTime(time->time().addMSecs(1));
    *relativeTime = relativeTime->addMSecs(1);
}
