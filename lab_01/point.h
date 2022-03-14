#ifndef POINT_H
#define POINT_H

#include "erorrs.h"
#include "cstdlib"

#include <cmath>

#define EPS 1e-3

typedef struct transform_coeff
{
    double x, y, z;
} transform_coeff;

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

error_code move_point_vector(point_vector &point_vec, transform_coeff move_coeff);

error_code scale_point_vector(point_vector &point_vec, point center, transform_coeff scale_coeff);

error_code rotate_point_vector(point_vector &point_vec, point center, transform_coeff rotate_coeff);

error_code deep_copy(point_vector &dst, point_vector &src);

#endif 
