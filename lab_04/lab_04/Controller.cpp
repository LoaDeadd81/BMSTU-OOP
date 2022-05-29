#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent), state(ControllerState::FREE), cur_floor(START_FLOOR - 1),
                                          target_floor(-1),
                                          direction(NO_DIR)
{
    for (bool &floor_statu: floor_status) floor_statu = false;
    QObject::connect(this, SIGNAL(target_added()), this, SLOT(on_floor()));
}

void Controller::on_passed_floor()
{
    cur_floor += direction;
    state = ControllerState::BUSY;
//    debug_print(__FUNCTION__);
    if (cur_floor == target_floor) cout << "Elevator stopped on " << cur_floor + 1 << " floor " << endl;
    else cout << "Elevator passing " << cur_floor + 1 << " floor " << endl;
    move();
}

void Controller::on_floor()
{
    if (!have_targets())
    {
        direction = NO_DIR;
        state = ControllerState::FREE;
        return;
    }
    new_target();
    set_direction();
//    debug_print(__FUNCTION__);
    move();
}

void Controller::move()
{
    if (cur_floor == target_floor)
    {
        del_target();
        emit stop_solution();
    }
    if (direction == UP) emit move_up_solution();
    if (direction == DOWN) emit move_down_solution();
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

void Controller::set_direction()
{
    direction = (cur_floor < target_floor) ? UP : DOWN;
}

void Controller::del_target()
{
    floor_status[cur_floor] = false;
}

bool Controller::new_up_target()
{
    bool res = false;
    int i = cur_floor - 1;
    for (; !res && i < FLOOR_NUM; i++) res = floor_status[i];
    if (res) target_floor = i - 1;
    return res;
}

bool Controller::new_down_target()
{
    bool res = false;
    int i = cur_floor - 1;
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
