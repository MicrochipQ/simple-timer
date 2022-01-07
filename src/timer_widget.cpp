#include <QMessageBox>
#include "timer_widget.h"

TimerWidget::TimerWidget(MainWindow *parent)
    : QWidget(parent)
{
    this->parent = parent;
    timer = new QTimer(this);

    setupUi();

    connect(startButton, &QPushButton::clicked, this, &TimerWidget::OnStart);
    connect(pauseButton, &QPushButton::clicked, this, &TimerWidget::OnPause);
    connect(stopButton, &QPushButton::clicked, this, &TimerWidget::OnStop);
    connect(timer, &QTimer::timeout, this, &TimerWidget::OnTick);

    OnStop();
}

void TimerWidget::setupUi()
{
    parent->setMinimumSize(340, 100);
    parent->setMaximumSize(680, 200);
    parent->resize(parent->minimumSize());

    layout = new QHBoxLayout();

    timeEdit = new QTimeEdit();
    timeEdit->setDisplayFormat("HH:mm:ss");
    layout->addWidget(timeEdit);

    startButton = new QPushButton("Start");
    layout->addWidget(startButton);

    pauseButton = new QPushButton("Pause");
    layout->addWidget(pauseButton);

    stopButton = new QPushButton("Stop");
    layout->addWidget(stopButton);

    setLayout(layout);
}

void TimerWidget::OnStart()
{
    if (timeEdit->time() == QTime(0, 0, 0, 0))
    {
        QMessageBox::warning(this, "Not a simple timer",
                             "ТЫ Чё ДУРАК?!",
                             QMessageBox::Yes | QMessageBox::YesToAll,
                             QMessageBox::Yes);
        return;
    }

    timeEdit->setReadOnly(true);

    startButton->hide();
    stopButton->show();
    pauseButton->show();

    timer->start(1000);
}

void TimerWidget::OnPause()
{
    timeEdit->setReadOnly(false);

    startButton->show();
    pauseButton->hide();

    timer->stop();
}

void TimerWidget::OnStop()
{
    timeEdit->setReadOnly(false);
    timeEdit->setTime(QTime(0, 0, 0));

    startButton->show();
    stopButton->hide();
    pauseButton->hide();

    timer->stop();
}

void TimerWidget::OnTick()
{
    timeEdit->setTime(timeEdit->time().addSecs(-1));
    if (timeEdit->time() <= QTime(0, 0, 0, 0))
    {
        OnStop();
        parent->trayIcon->showMessage("В гробу перевернулся...", "Ура! Таймер наконец-то умер! :)");
    }
}
