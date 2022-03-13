#include "model.h"

model init_model()
{
    model tmp;
    tmp.center = {0, 0};
    tmp.points = init_point_vector();
    tmp.links = init_line_vector();
    return tmp;
}

void del_model(model &figure)
{
    del_point_vector(figure.points);
    del_line_vector(figure.links);
}

void reinit_model(model &figure)
{
    del_model(figure);
    figure = init_model();
}

bool is_model_exist(model &figure)
{
    return is_point_vector_exist(figure.points) && is_line_vec_exist(figure.links);
}
