#include "point.h"

void yz_rotate(point &p, point &center, double cx);

void xz_rotate(point &p, point &center, double cy);

void xy_rotate(point &p, point &center, double cz);

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

error_code move_point_vector(point_vector &point_vec, double dx, double dy, double dz)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            move_point(point_vec.arr[i], dx, dy, dz);
    return rc;
}

error_code scale_point_vector(point_vector &point_vec, point center, double kx, double ky, double kz)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            scale_point(point_vec.arr[i], center, kx, ky, kz);
    return rc;
}

error_code rotate_point_vector(point_vector &point_vec, point center, double cx, double cy, double cz)
{
    error_code rc = SUCCESS;
    if (point_vec.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
        for (int i = 0; i < point_vec.len; i++)
            rotate_point(point_vec.arr[i], center, cx, cy, cz);
    return rc;
}

void move_point(point &cur_point, double dx, double dy, double dz)
{
    cur_point.x += dx;
    cur_point.y += dy;
    cur_point.z += dz;
}

void scale_point(point &cur_point, point center, double kx, double ky, double kz)
{
    cur_point.x = kx * cur_point.x + (1 - kx) * center.x;
    cur_point.y = ky * cur_point.y + (1 - ky) * center.y;
    cur_point.z = kz * cur_point.z + (1 - kz) * center.z;
}


void rotate_point(point &cur_point, point center, double cx, double cy, double cz)
{
    yz_rotate(cur_point, center, cx);
    xz_rotate(cur_point, center, cy);
    xy_rotate(cur_point, center, cz);
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
