#include "Elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    QObject::connect(&cabin, SIGNAL(passed_floor()), &controller, SLOT(waited()));
    QObject::connect(&cabin, SIGNAL(ready_move()), &controller, SLOT(waited()));
    QObject::connect(&cabin, SIGNAL(standing()), &controller, SLOT(chill()));
    QObject::connect(&controller, SIGNAL(move_up_solution()), &cabin, SLOT(move_up()));
    QObject::connect(&controller, SIGNAL(move_down_solution()), &cabin, SLOT(move_down()));
    QObject::connect(&controller, SIGNAL(stop_solution()), &cabin, SLOT(wait()));
    QObject::connect(&controller, SIGNAL(stand_solution()), &cabin, SLOT(stop()));
}

void Elevator::call(int floor)
{
    controller.set_target(floor);
}
