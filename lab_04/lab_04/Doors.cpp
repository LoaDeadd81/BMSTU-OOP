#include "Doors.h"

Doors::Doors(QObject *parent) : QObject(parent), state(DoorState::CLOSED)
{
    open_timer.setSingleShot(true);
    open_timer.setInterval(DOOR_MOVE_TIME);
    close_timer.setSingleShot(true);
    close_timer.setInterval(DOOR_MOVE_TIME);
    wait_timer.setSingleShot(true);
    wait_timer.setInterval(DOOR_WAIT_TIME);

    connect(&open_timer, SIGNAL(timeout()), this, SLOT(opening()));
    connect(&wait_timer, SIGNAL(timeout()), this, SLOT(close()));
    connect(&close_timer, SIGNAL(timeout()), this, SLOT(closing()));

}

void Doors::open()
{ 
    if(state != DoorState::CLOSED && state != DoorState::CLOSING)
        return;
    state = DoorState::OPENING;
    cout << "Doors are opening" << endl;
    open_timer.start();
}

void Doors::opening()
{
    if(state != DoorState::OPENING)
        return;
    state = DoorState::OPENED;
    cout << "Doors are opened" << endl;
    wait_timer.start();
}

void Doors::close()
{
    if(state != DoorState::OPENED)
        return;
    state = DoorState::CLOSING;
    cout << "Doors are closing" << endl;
    close_timer.start();
}

void Doors::closing()
{
    if(state != DoorState::CLOSING)
        return;
    state = DoorState::CLOSED;
    cout << "Doors are closed" << endl;
    emit closed();
}
