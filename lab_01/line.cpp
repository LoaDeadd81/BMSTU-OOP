#include "line.h"

line_vector init_line_vector()
{
    return {nullptr, 0};
}

void del_line_vector(line_vector &line_vec)
{
    delete[] line_vec.arr;
    line_vec = init_line_vector();
}

bool is_line_vec_exist(line_vector &line_vec)
{
    return line_vec.arr != nullptr;
}

error_code alloc_line_vector(line_vector &line_vec, int num)
{
    error_code rc = SUCCESS;
    line_vec.arr = (line *) calloc(num, sizeof(line));
    if (line_vec.arr == nullptr)
        rc = MEMORY_ERROR;
    else
        line_vec.len = num;
    return rc;
}

error_code check_line_vector(line_vector &line_vec, int points_num)
{
    error_code rc = SUCCESS;
    int i = 0;
    while (i < points_num && rc == SUCCESS)
    {
        if ((line_vec.arr[i].start_index >= points_num || line_vec.arr[i].end_index >= points_num) ||
            (line_vec.arr[i].start_index == line_vec.arr[i].end_index))
            rc = INPUT_MODEL_ERROR;
        i++;
    }
    return rc;
}


