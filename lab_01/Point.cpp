#include "Point.h"

error_code input_tmp_points(points_type &points, FILE *f);


void move_point(point_type &point, const transform_data &data);

void scale_point(point_type &point, const point_type &center, const transform_data &data);

void rotate_point(point_type &point, const point_type &center, const transform_data &data);

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
    if (points.array != nullptr || f == nullptr)
        rc = MEM_ERROR;
    else
    {
        points_type tmp_points = init_points();
        rc = input_tmp_points(tmp_points, f);
        if (rc == SUCCESS)
            points = tmp_points;
        else
            free_points(tmp_points);
    }
    return rc;
}

error_code move_points(points_type &points, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array != nullptr)
        rc = MEM_ERROR;
    for (int i = 0; i < points.len; i++)
        move_point(points.array[i], data);
}

error_code scale_points(points_type &points, const point_type &center, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array != nullptr)
        rc = MEM_ERROR;
    else
    {
        for (int i = 0; i < points.len; i++)
            scale_point(points.array[i], center, data);
    }
    return rc;
}

error_code rotate_points(points_type &points, const point_type &center, const transform_data &data)
{
    error_code rc = SUCCESS;
    if (points.array != nullptr)
        rc = MEM_ERROR;
    else
    {
        for (int i = 0; i < points.len; i++)
            rotate_point(points.array[i], center, data);
    }
    return rc;
}

error_code input_points_num(int &num, FILE *f);

error_code input_points_array(points_type &points, int num, FILE *f);

error_code alloc_points_array(points_type &points, int num);

error_code input_point(point_type &point, FILE *f);

error_code input_tmp_points(points_type &points, FILE *f)
{
    int num = 0;
    error_code rc = input_points_num(num, f);
    if (rc == SUCCESS)
    {
        rc = alloc_points_array(points, num);
        if (rc == SUCCESS)
        {
            rc = input_points_array(points, num, f);
            if (rc != SUCCESS)
                free_points(points);
        }
    }
    return rc;
}

error_code input_points_num(int &num, FILE *f)
{
    error_code rc = SUCCESS;
    if (fscanf(f, "%d", &num) != 1 || num < 1)
        rc = BAD_MODEL_DATA;
    return rc;
}

error_code input_points_array(points_type &points, int num, FILE *f)
{
    error_code rc = SUCCESS;
    if (points.array == nullptr)
        rc = MEM_ERROR;
    else
    {
        for (int i = 0; i < rc == SUCCESS && i < num; i++)
            rc = input_point(points.array[i], f);
    }
    return rc;
}

error_code alloc_points_array(points_type &points, int num)
{
    error_code rc = SUCCESS;
    points.array = (point_type *) malloc(sizeof(point_type) * num);
    if (points.array == nullptr)
        rc = MEM_ERROR;
    else
        points.len = num;
    return rc;
}

error_code input_point(point_type &point, FILE *f)
{
    error_code rc = SUCCESS;
    if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
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


void yz_rotate(point_type &p, const point_type &center, double cx);

void xz_rotate(point_type &p, const point_type &center, double cy);

void xy_rotate(point_type &p, const point_type &center, double cz);

void rotate_point(point_type &point, const point_type &center, const transform_data &data)
{
    yz_rotate(point, center, data.a);
    xz_rotate(point, center, data.b);
    xy_rotate(point, center, data.c);
}

double degree_to_radians(double degree)
{
    return degree * M_PI / 180.0;
}

void yz_rotate(point_type &p, const point_type &center, double cx)
{
    double radians = degree_to_radians(cx);
    double dy = p.y - center.y, dz = p.z - center.z;
    p.y = center.y + dy * cos(radians) - dz * sin(radians);
    p.z = center.z + dy * sin(radians) + dz * cos(radians);
}

void xz_rotate(point_type &p, const point_type &center, double cy)
{
    double radians = degree_to_radians(cy);
    double dx = p.x - center.x, dz = p.z - center.z;
    p.x = center.x + dx * cos(radians) + dz * sin(radians);
    p.z = center.z - dx * sin(radians) + dz * cos(radians);
}

void xy_rotate(point_type &p, const point_type &center, double cz)
{
    double radians = degree_to_radians(cz);
    double dx = p.x - center.x, dy = p.y - center.y;
    p.x = center.x + dx * cos(radians) - dy * sin(radians);
    p.y = center.y + dx * sin(radians) + dy * cos(radians);
}

