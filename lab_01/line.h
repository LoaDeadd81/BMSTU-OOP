#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct line
{
    int start_index, end_index;
} line;

typedef struct line_vector
{
    line *arr;
    int len;
} line_vector;

line_vector init_line_vector();

void del_line_vector(line_vector &line_vec);

bool is_line_vec_exist(line_vector &line_vec);

error_code alloc_line_vector(line_vector &line_vec, int num);

error_code check_line_vector(line_vector &line_vec, int points_num);

error_code deep_copy(line_vector &dst, line_vector &src);

#endif 
