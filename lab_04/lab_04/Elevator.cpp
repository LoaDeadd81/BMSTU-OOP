#include "Elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    QObject::connect(&cabin, SIGNAL(passed_floor()), &controller, SLOT(on_passed_floor()));
    QObject::connect(&cabin, SIGNAL(on_floor()), &controller, SLOT(on_floor()));
    QObject::connect(&controller, SIGNAL(move_up_solution()), &cabin, SLOT(move_up()));
    QObject::connect(&controller, SIGNAL(move_down_solution()), &cabin, SLOT(move_down()));
    QObject::connect(&controller, SIGNAL(stop_solution()), &cabin, SLOT(wait()));
}

void Elevator::call(int floor)
{
    controller.set_target(floor);
}
