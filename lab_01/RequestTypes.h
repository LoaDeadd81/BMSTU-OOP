#ifndef REQUESTTYPES_H
#define REQUESTTYPES_H

#include <cstdio>
#include <QGraphicsScene>

typedef struct transform_data
{
    double a, b, c;
} transform_data;

typedef struct input_request
{
    const char *filename;
} input_request;

typedef struct draw_request
{
    QGraphicsScene *scene;
} draw_request;

typedef struct move_request
{
    transform_data move_data;
} move_request;

typedef struct scale_request
{
    points_type center;
    transform_data scale_data;
} scale_request;

typedef struct rotate_request
{
    points_type center;
    transform_data rotate_data;
} rotate_request;


#endif 
