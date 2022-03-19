#ifndef POINT_H
#define POINT_H

#include "ErrorType.h"

#include <cstdlib>
#include <cstdio>

typedef struct point_type
{
    double x, y, z;
} point_type;

typedef struct points_type
{
    point_type *array;
    int len;
} points_type;

typedef struct transform_data
{
    double a, b, c;
} transform_data;

points_type init_points();

void free_points(points_type &points);

int len(const points_type &points);

error_code input_points(points_type &points, FILE *f);

error_code move_points(points_type &points, const transform_data &data);

error_code scale_points(points_type &points, const point_type &center, const transform_data &data);

error_code rotate_points(points_type &points, const point_type &center, const transform_data &data);

error_code deep_copy(points_type &dst, const points_type &src);

#endif 
