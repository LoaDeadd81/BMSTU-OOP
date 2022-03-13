#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "model.h"
#include "point.h"
#include "erorrs.h"


typedef struct move_request
{
    double dx, dy, dz;
} move_request;

typedef struct scale_request
{
    point center;
    double kx, ky, kz;
} scale_request;

typedef struct rotate_request
{
    point center;
    double cx, cy, cz;
} rotate_request;

error_code move_model(model &figure, move_request &request);

error_code scale_model(model &figure, scale_request &request);

error_code rotate_model(model &figure, rotate_request &request);

#endif 
