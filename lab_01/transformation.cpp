#include "transformation.h"

error_code move_model(model &figure, move_request &request)
{
    model tmp_figure = init_model();
    error_code rc = deep_copy(tmp_figure, figure);
    if(rc == SUCCESS)
        rc = move_point_vector(figure.points, {request.dx, request.dy, request.dz});
    return rc;
}

error_code scale_model(model &figure, scale_request &request)
{
    model tmp_figure = init_model();
    error_code rc = deep_copy(tmp_figure, figure);
    if(rc == SUCCESS)
        rc = scale_point_vector(figure.points, request.center, {request.kx, request.ky, request.kz});
    return rc;
}

error_code rotate_model(model &figure, rotate_request &request)
{
    model tmp_figure = init_model();
    error_code rc = deep_copy(tmp_figure, figure);
    if(rc == SUCCESS)
        rc = rotate_point_vector(figure.points, request.center, {request.cx, request.cy, request.cz});
    return rc;

}
