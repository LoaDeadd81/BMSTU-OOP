#include "transformation.h"

error_code move_model(model &figure, move_request &request)
{
    error_code rc = move_point_vector(figure.points, request.dx, request.dy, request.dz);
    return rc;
}

error_code scale_model(model &figure, scale_request &request)
{
    error_code rc = scale_point_vector(figure.points, request.center, request.kx, request.ky, request.kz);
    return rc;
}

error_code rotate_model(model &figure, rotate_request &request)
{
    error_code rc = rotate_point_vector(figure.points, request.center, request.cx, request.cy, request.cz);
    return rc;
}
