#include "Point.h"

error_code alloc_points_array(points_type &points, int num);

error_code input_points_num(int &num, FILE *f);

error_code input_point(point_type &point, FILE *f);

void move_point(point_type &point, const transform_data &data);

void scale_point(point_type &point, const point_type &center, const transform_data &data);

void rotate_point(point_type &point, const point_type &center, const transform_data &data);

error_code input_points_arr(points_type &points, FILE *f);

points_type init_points()
{
    return {nullptr, 0};
}

void free_points(points_type &points)
{
    free(points.array);
}

int len(const points_type &points)
{
    return points.len;
}

error_code input_points(points_type &points, FILE *f)
{
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        int num = 0;
        rc = input_points_num(num, f);
        if (rc == SUCCESS)
        {
            rc = alloc_points_array(points, num);
            if (rc == SUCCESS)
            {
                //todo смещение уровня абстракции
                rc = input_points_arr(points, f);
                if (rc != SUCCESS)
                    free_points(points);
            }
        }
    }
    return rc;
}

error_code move_points(points_type &points, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array == nullptr)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; i < points.len; i++)
            move_point(points.array[i], data);
    return rc;
}

error_code scale_points(points_type &points, const point_type &center, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array == nullptr)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; i < points.len; i++)
            scale_point(points.array[i], center, data);
    return rc;
}

error_code rotate_points(points_type &points, const point_type &center, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array == nullptr)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; i < points.len; i++)
            rotate_point(points.array[i], center, data);
    return rc;
}

error_code deep_copy(points_type &dst, const points_type &src)
{
    error_code rc = SUCCESS;
    if (src.array == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        rc = alloc_points_array(dst, src.len);
        if (rc == SUCCESS)
            for (int i = 0; i < src.len; i++)
                dst.array[i] = src.array[i];
    }
    return rc;
}

void asigne(points_type &dst, const points_type &src)
{
    free_points(dst);
    dst = src;
}

error_code input_points_num(int &num, FILE *f)
{
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else if (fscanf(f, "%d", &num) != 1 || num < 1)
        rc = BAD_MODEL_DATA;
    return rc;
}

error_code alloc_points_array(points_type &points, int num)
{
    error_code rc = SUCCESS;
    if (num < 1)
        rc = MEM_ERROR;
    else
    {
        points.array = (point_type *) malloc(sizeof(point_type) * num);
        if (points.array == nullptr)
            rc = MEM_ERROR;
        else
            points.len = num;
    }
    return rc;
}

error_code input_points_arr(points_type &points, FILE *f)
{
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.len; i++)
            rc = input_point(points.array[i], f);
    return rc;
}

error_code input_point(point_type &point, FILE *f)
{
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = BAD_MODEL_DATA;
    return rc;
}

void move_point(point_type &point, const transform_data &data)
{
    point.x += data.a;
    point.y += data.b;
    point.z += data.c;
}

void scale_point(point_type &point, const point_type &center, const transform_data &data)
{
    point.x = data.a * point.x + (1 - data.a) * center.x;
    point.y = data.b * point.y + (1 - data.b) * center.y;
    point.z = data.c * point.z + (1 - data.c) * center.z;
}


void yz_rotate(point_type &p, double cx);

void xz_rotate(point_type &p, double cy);

void xy_rotate(point_type &p, double cz);

void move_to_center(point_type &p, const point_type &center);

void move_back(point_type &p, const point_type &center);

void rotate_point(point_type &point, const point_type &center, const transform_data &data)
{
    //todo фигура двигается 3 раза
    move_to_center(point, center);

    yz_rotate(point, data.a);
    xz_rotate(point, data.b);
    xy_rotate(point, data.c);

    move_back(point, center);
}

double degree_to_radians(double degree)
{
    return degree * M_PI / 180.0;
}

void yz_rotate(point_type &p, double cx)
{
    double radians = degree_to_radians(cx);
    double tmp_y = p.y, tmp_z = p.z;
    p.y = tmp_y * cos(radians) - tmp_z * sin(radians);
    p.z = tmp_y * sin(radians) + tmp_z * cos(radians);
}

void xz_rotate(point_type &p, double cy)
{
    double radians = degree_to_radians(cy);
    double tmp_x = p.x, tmp_z = p.z;
    p.x = tmp_x * cos(radians) + tmp_z * sin(radians);
    p.z = -tmp_x * sin(radians) + tmp_z * cos(radians);
}

void xy_rotate(point_type &p, double cz)
{
    double radians = degree_to_radians(cz);
    double tmp_y = p.y, tmp_x = p.x;
    p.x = tmp_x * cos(radians) - tmp_y * sin(radians);
    p.y = tmp_x * sin(radians) + tmp_y * cos(radians);
}

void move_to_center(point_type &p, const point_type &center)
{
    transform_data move_data = {-center.x, -center.y, -center.z};
    move_point(p, move_data);
}

void move_back(point_type &p, const point_type &center)
{
    transform_data move_data = {center.x, center.y, center.z};
    move_point(p, move_data);
}
