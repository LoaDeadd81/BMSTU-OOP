#ifndef POINT_H
#define POINT_H

#include "erorrs.h"
#include "cstdlib"

#include <cmath>

typedef struct point
{
    double x, y, z;
} point;

typedef struct point_vector
{
    point *arr;
    int len;
} point_vector;

point_vector init_point_vector();

void del_point_vector(point_vector &point_vec);

bool is_point_vector_exist(point_vector &point_vec);

int get_points_num(point_vector &point_vec);

error_code alloc_point_vector(point_vector &point_vec, int num);

error_code move_point_vector(point_vector &point_vec, double dx, double dy, double dz);

error_code scale_point_vector(point_vector &point_vec, point center, double kx, double ky, double kz);

error_code rotate_point_vector(point_vector &point_vec, point center, double cx, double cy, double cz);

void move_point(point &cur_point, double dx, double dy, double dz);

void scale_point(point &cur_point, point center, double kx, double ky, double kz);

void rotate_point(point &cur_point, point center, double cx, double cy, double cz);

#endif 
