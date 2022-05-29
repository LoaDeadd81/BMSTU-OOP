#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Cabin.h"
#include "Controller.h"

class Elevator : public QObject
{
Q_OBJECT
public:
    Elevator(QObject *parent = nullptr);
    void call(int floor);
private:
    Cabin cabin;
    Controller controller;
};

#endif
