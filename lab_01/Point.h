#ifndef POINT_H
#define POINT_H

#include "ErrorType.h"
#include "RequestTypes.h"

typedef struct point_type
{
    double x, y, z;
} point_type;

typedef struct points_type
{
    point_type *array;
    int len;
} points_type;

points_type init_points();

void free_points(points_type &points);

int len();

error_code input_points(points_type &points, const FILE *f);

error_code move_points(points_type &points, const transform_data &data);

error_code scale_points(points_type &points, const point_type &center, const transform_data &data);

error_code rotate_points(points_type &points, const point_type &center, const transform_data &data);

#endif 
