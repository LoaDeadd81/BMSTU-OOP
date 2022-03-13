#include "model_io.h"

error_code read_model(model &figure, const char *filename);

error_code check_model(model &figure);

error_code read_points(point_vector &point_vec, FILE *f);

error_code read_links(line_vector &line_vec, FILE *f);


error_code input_model(model &figure, read_request &request)
{
    error_code rc = read_model(figure, request.file_name);
    if(rc == SUCCESS)
        rc = check_model(figure);
    return rc;
}

error_code read_model(model &figure, const char *filename)
{
    if (is_model_exist(figure))
        reinit_model(figure);
    error_code rc = SUCCESS;
    FILE *f = fopen(filename, "r");
    if (f == nullptr)
        rc = INPUT_MODEL_ERROR;
    else
    {
        rc = read_points(figure.points, f);
        if (rc == SUCCESS)
            rc = read_links(figure.links, f);
    }
    fclose(f);
    return rc;
}

error_code check_model(model &figure)
{
    error_code rc = check_line_vector(figure.links, get_points_num(figure.points));
    return rc;
}

error_code read_points(point_vector &point_vec, FILE *f)
{
    error_code rc = SUCCESS;
    int num = 0;
    if (fscanf(f, "%d", &num) != 1 || num < 1)
        rc = INPUT_MODEL_ERROR;
    if (rc == SUCCESS)
    {
        rc = alloc_point_vector(point_vec, num);
        if (rc == SUCCESS)
        {
            int i = 0;
            while (i < num && rc == SUCCESS)
            {
                int read_num = fscanf(f, "%lf %lf %lf", &point_vec.arr[i].x, &point_vec.arr[i].y, &point_vec.arr[i].z);
                if (read_num != 3)
                    rc = INPUT_MODEL_ERROR;
                i++;
            }
        }
    }
    if (rc != SUCCESS)
        del_point_vector(point_vec);
    return rc;
}

error_code read_links(line_vector &line_vec, FILE *f)
{
    error_code rc = SUCCESS;
    int num = 0;
    if (fscanf(f, "%d", &num) != 1 || num < 1)
        rc = INPUT_MODEL_ERROR;
    if (rc == SUCCESS)
    {
        rc = alloc_line_vector(line_vec, num);
        if (rc == SUCCESS)
        {
            int i = 0;
            while (i < num && rc == SUCCESS)
            {
                int read_num = fscanf(f, "%d %d", &line_vec.arr[i].start_index, &line_vec.arr[i].end_index);
                if (read_num != 2)
                    rc = INPUT_MODEL_ERROR;
                i++;
            }
        }
    }
    if (rc != SUCCESS)
        del_line_vector(line_vec);
    return rc;
}
