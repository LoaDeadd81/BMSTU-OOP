#include "Cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent), state(CabinState::STAND)
{
    move_timer.setSingleShot(true);
    move_timer.setInterval(MOVE_TIME);
    connect(this, SIGNAL(stopped()), &doors, SLOT(open()));
    connect(&doors, SIGNAL(closed()), this, SLOT(stop()));
    connect(&move_timer, SIGNAL(timeout()), this, SLOT(on_passed_floor()));
}

void Cabin::move_up()
{
    if (state != CabinState::MOVE_UP && state != CabinState::STAND)
        return;
    state = CabinState::MOVE_UP;
    move_timer.start();
}

void Cabin::move_down()
{
    if (state != CabinState::MOVE_DOWN && state != CabinState::STAND)
        return;
    state = CabinState::MOVE_DOWN;
    move_timer.start();
}

void Cabin::on_passed_floor()
{
    emit passed_floor();
}

void Cabin::wait()
{
//    if(state == CabinState::WAIT)
//        return;
    state = CabinState::WAIT;
    emit stopped();
}

void Cabin::stop()
{
    if (state != CabinState::WAIT)
        return;
    state = CabinState::STAND;
    emit on_floor();
}



