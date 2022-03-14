#include "point.h"

void move_point(point &cur_point, transform_coeff &move_coeff);

void scale_point(point &cur_point, point center, transform_coeff &scale_coeff);

void rotate_point(point &cur_point, point center, transform_coeff &rotate_coeff);

void yz_rotate(point &p, point &center, double cx);

void xz_rotate(point &p, point &center, double cy);

void xy_rotate(point &p, point &center, double cz);

bool eq_points(point &a, point &b);

double degree_to_radians(double degree)
{
    return degree * M_PI / 180.0;
}

point_vector init_point_vector()
{
    return {nullptr, 0};
}

void del_point_vector(point_vector &point_vec)
{
    delete[] point_vec.arr;
    point_vec = init_point_vector();
}

bool is_point_vector_exist(point_vector &point_vec)
{
    return point_vec.arr != nullptr;
}

int get_points_num(point_vector &point_vec)
{
    return point_vec.len;
}

error_code alloc_point_vector(point_vector &point_vec, int num)
{
    error_code rc = SUCCESS;
    point_vec.arr = (point *) calloc(num, sizeof(point));
    if (point_vec.arr == nullptr)
        rc = MEMORY_ERROR;
    else
        point_vec.len = num;
    return rc;
}

error_code move_point_vector(point_vector &point_vec, transform_coeff move_coeff)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            move_point(point_vec.arr[i], move_coeff);
    return rc;
}

error_code scale_point_vector(point_vector &point_vec, point center, transform_coeff scale_coeff)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            scale_point(point_vec.arr[i], center, scale_coeff);
    return rc;
}

error_code rotate_point_vector(point_vector &point_vec, point center, transform_coeff rotate_coeff)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            rotate_point(point_vec.arr[i], center, rotate_coeff);
    return rc;
}

void move_point(point &cur_point, transform_coeff &move_coeff)
{
    cur_point.x += move_coeff.x;
    cur_point.y += move_coeff.y;
    cur_point.z += move_coeff.z;
}

void scale_point(point &cur_point, point center, transform_coeff &scale_coeff)
{
    cur_point.x = scale_coeff.x * cur_point.x + (1 - scale_coeff.x) * center.x;
    cur_point.y = scale_coeff.y * cur_point.y + (1 - scale_coeff.y) * center.y;
    cur_point.z = scale_coeff.z * cur_point.z + (1 - scale_coeff.z) * center.z;
}


void rotate_point(point &cur_point, point center, transform_coeff &rotate_coeff)
{
    if(!eq_points(cur_point, center))
    {
        yz_rotate(cur_point, center, rotate_coeff.x);
        xz_rotate(cur_point, center, rotate_coeff.y);
        xy_rotate(cur_point, center, rotate_coeff.z);
    }
}

void yz_rotate(point &p, point &center, double cx)
{
    double radians = degree_to_radians(cx);
    double dy = p.y - center.y, dz = p.z - center.z;
    p.y = center.y + dy * cos(radians) - dz * sin(radians);
    p.z = center.z + dy * sin(radians) + dz * cos(radians);
}

void xz_rotate(point &p, point &center, double cy)
{
    double radians = degree_to_radians(cy);
    double dx = p.x - center.x, dz = p.z - center.z;
    p.x = center.x + dx * cos(radians) + dz * sin(radians);
    p.z = center.z - dx * sin(radians) + dz * cos(radians);
}

void xy_rotate(point &p, point &center, double cz)
{
    double radians = degree_to_radians(cz);
    double dx = p.x - center.x, dy = p.y - center.y;
    p.x = center.x + dx * cos(radians) - dy * sin(radians);
    p.y = center.y + dx * sin(radians) + dy * cos(radians);
}


bool eq_points(point &a, point &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS && fabs(a.z - b.z) < EPS;
}

error_code deep_copy(point_vector &dst, point_vector &src)
{
    error_code rc = alloc_point_vector(dst, src.len);
    if(rc == SUCCESS)
        memcpy(dst.arr, src.arr, sizeof(point) * src.len);
    return rc;
}
