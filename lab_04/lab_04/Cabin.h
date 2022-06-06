#ifndef CABIN_H
#define CABIN_H

#include "Doors.h"

#define MOVE_TIME 1000

enum class CabinState
{
    MOVE_UP, MOVE_DOWN, WAITING, STAND, MOVED, READY
};

class Cabin : public QObject
{
Q_OBJECT
public slots:
    void move_up();
    void move_down();
    void moved();
    void wait();
    void ready();
    void stop();
public:
    Cabin(QObject *parent = nullptr);
signals:
    void passed_floor();
    void stopped();
    void ready_move();
    void standing();
private:
    CabinState state;
    QTimer move_timer;
    Doors doors;
};

#endif
