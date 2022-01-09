#pragma once

#include <QBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QTime>
#include <QTimeEdit>
#include <QTimer>
#include <QWidget>

class StopwatchWidget : public QWidget
{
    Q_OBJECT

public:
    StopwatchWidget(QWidget * = nullptr);

private:
    QWidget *parent;
    QVBoxLayout *layout;
    QHBoxLayout *controlsLayout;
    QListWidget *roundsList;
    QTimeEdit *time;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QPushButton *lapButton;
    QTimer *timer;
    QTime *relativeTime;

    void setupUi();
    void OnStart();
    void OnPause();
    void OnReset();
    void OnLap();
    void OnTick();
};
