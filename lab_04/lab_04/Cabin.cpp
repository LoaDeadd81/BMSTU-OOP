#include "Cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent), state(CabinState::STAND)
{
    move_timer.setSingleShot(true);
    move_timer.setInterval(MOVE_TIME);
    connect(&move_timer, SIGNAL(timeout()), this, SLOT(moved()));
    connect(this, SIGNAL(stopped()), &doors, SLOT(open()));
    connect(&doors, SIGNAL(closed()), this, SLOT(ready()));
}

void Cabin::move_up()
{
    if (state != CabinState::MOVED && state != CabinState::STAND && state != CabinState::READY)
        return;
    state = CabinState::MOVING_UP;
    move_timer.start();
}

void Cabin::move_down()
{
    if (state != CabinState::MOVED && state != CabinState::STAND && state != CabinState::READY)
        return;
    state = CabinState::MOVING_DOWN;
    move_timer.start();
}

void Cabin::moved()
{
    if (state != CabinState::MOVING_UP && state != CabinState::MOVING_DOWN)
        return;
    state = CabinState::MOVED;
    emit passed_floor();
}

void Cabin::wait()
{
    if(state != CabinState::READY && state != CabinState::MOVED && state != CabinState::STAND)
        return;
    state = CabinState::WAITING;
    emit stopped();
}

void Cabin::ready()
{
    if(state != CabinState::WAITING)
        return;
    state = CabinState::READY;
    emit ready_move();
}

void Cabin::stop()
{
    if (state != CabinState::READY)
        return;
    state = CabinState::STAND;
    emit standing();
}



