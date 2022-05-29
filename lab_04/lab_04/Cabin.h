#ifndef CABIN_H
#define CABIN_H

#include "Doors.h"

#define MOVE_TIME 1000

enum class CabinState
{
    MOVE_UP, MOVE_DOWN, WAIT, STAND
};

class Cabin : public QObject
{
Q_OBJECT
public slots:
    void move_up();
    void move_down();
    void wait();
    void stop();
    void on_passed_floor();
public:
    Cabin(QObject *parent = nullptr);
signals:
    void passed_floor();
    void on_floor();
    void stopped();
private:
    CabinState state;
    QTimer move_timer;
    Doors doors;
};

#endif
