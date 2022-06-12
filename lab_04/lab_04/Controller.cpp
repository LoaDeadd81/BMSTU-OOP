#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent), state(ControllerState::FREE), cur_floor(START_FLOOR - 1),
                                          target_floor(-1),
                                          direction(NO_DIR)
{
    for (bool &floor_statu: floor_status) floor_statu = false;
    QObject::connect(this, SIGNAL(target_added()), this, SLOT(solve()));
    QObject::connect(this, SIGNAL(ready()), this, SLOT(solve()));
    QObject::connect(this, SIGNAL(solved()), this, SLOT(inform()));
}

void Controller::solve()
{
    if (state != ControllerState::FREE && state != ControllerState::READY)
        return;
    state = ControllerState::SOLVE;
    new_target();
    set_direction();
    emit solved();
}

void Controller::inform()
{
    if (state != ControllerState::SOLVE)
        return;
    state = ControllerState::WAIT;
    if (!have_targets())
            emit stand_solution();
    else if (direction == NO_DIR)
    {
        del_target();
        cout << "Elevator stopped on " << cur_floor + 1 << " floor" << endl;
        emit stop_solution();
    }
    else if (direction == UP)
            emit move_up_solution();
    else if (direction == DOWN)
            emit move_down_solution();
}

void Controller::waited()
{
    if (state != ControllerState::WAIT)
        return;
    state = ControllerState::READY;
    if (direction != NO_DIR)
        cout << "Elevator passed " << cur_floor + 1 << " floor" << endl;
    cur_floor += direction;
    emit ready();
}

void Controller::chill()
{
    if (state != ControllerState::WAIT)
        return;
    state = ControllerState::FREE;
}

void Controller::set_target(int floor)
{
    floor_status[floor - 1] = true;
    emit target_added();
}

bool Controller::have_targets()
{
    bool res = false;
    for (int i = 0; !res && i < FLOOR_NUM; i++) res = floor_status[i];
    return res;
}

void Controller::new_target()
{
    if (direction != DOWN)
    {
        bool found = new_up_target();
        if (!found)
            new_down_target();
    }
    else
    {
        bool found = new_down_target();
        if (!found)
            new_up_target();
    }
}

void Controller::update_target()
{
    if (direction != DOWN)
    {
        bool found = new_up_target();
        if (!found)
            new_down_target();
    }
    else
    {
        bool found = new_down_target();
        if (!found)
            new_up_target();
    }
}

void Controller::set_direction()
{
    if (cur_floor == target_floor)
        direction = NO_DIR;
    else
        direction = (cur_floor < target_floor) ? UP : DOWN;
}

void Controller::del_target()
{
    floor_status[cur_floor] = false;
}

bool Controller::new_up_target()
{
    bool res = false;
    int i = cur_floor;
    for (; !res && i < FLOOR_NUM; i++) res = floor_status[i];
    if (res) target_floor = i - 1;
    return res;
}

bool Controller::new_down_target()
{
    bool res = false;
    int i = cur_floor;
    for (; !res && i >= 0; i--) res = floor_status[i];
    if (res) target_floor = i + 1;
    return res;
}

void Controller::debug_print(string funk)
{
    cout << "Funk: " << funk << endl;
    cout << "State: " << static_cast<int>(state) << endl;
    cout << "cur_floor: " << cur_floor << endl;
    cout << "target_floor " << target_floor << endl;
    cout << "dir: " << direction << endl;
    for (int i = 0; i < FLOOR_NUM; i++)
        cout << i << " : " << floor_status[i] << endl;
    cout << "===============================" << endl;
}
