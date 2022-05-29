#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <list>
#include <iostream>
#include <string>

using namespace std;

#define UP 1
#define NO_DIR 0
#define DOWN -1

#define FLOOR_NUM 9
#define START_FLOOR 1

template<typename Type>
using list = std::list<Type>;

enum class ControllerState
{
    BUSY, FREE
};

class Controller : public QObject
{
Q_OBJECT
public slots:
    void on_passed_floor();
    void on_floor();
public:
    Controller(QObject *parent = nullptr);
    void set_target(int floor);
signals:
    void move_up_solution();
    void move_down_solution();
    void stop_solution();
    void target_added();
private:
    ControllerState state;
    int cur_floor;
    int target_floor;
    int direction;
    bool floor_status[FLOOR_NUM];

    void move();
    bool have_targets();
    void new_target();
    void set_direction();
    void del_target();
    bool new_up_target();
    bool new_down_target();
    void debug_print(string funk);
};

#endif
