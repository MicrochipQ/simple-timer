#pragma once

#include <QBoxLayout>
#include <QPushButton>
#include <QTime>
#include <QTimeEdit>
#include <QTimer>
#include <QWidget>

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    TimerWidget(QWidget * = nullptr);

private:
    QWidget *parent;
    QHBoxLayout *layout;
    QTimeEdit *timeEdit;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QTimer *timer;

    void setupUi();

    void OnStart();
    void OnPause();
    void OnStop();
    void OnTick();
};
