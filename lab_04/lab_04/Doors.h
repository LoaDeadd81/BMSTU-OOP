#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include <iostream>

using namespace std;

#define DOOR_MOVE_TIME 500
#define DOOR_WAIT_TIME 1000

enum class DoorState
{
    OPENED, CLOSED, OPENING, CLOSING
};

class Doors : public QObject
{
Q_OBJECT
public slots:
    void open();
    void opening();
    void close();
    void closing();

public:
    Doors(QObject *parent = nullptr);

signals:
    void closed();

private:
    DoorState state;
    QTimer open_timer;
    QTimer close_timer;
    QTimer wait_timer;
};

#endif
