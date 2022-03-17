#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include "Point.h"
#include "Edge.h"
#include "ErrorType.h"
#include "RequestTypes.h"

#include <cstdio>

typedef struct frame_model
{
    points_type points;
    edges_type edges;
} frame_model;

frame_model init_model();

error_code input_model(frame_model &model, const input_request &request);

error_code draw_model(frame_model &model, draw_request &request);

error_code move_model(frame_model &model, const move_request &request);

error_code scale_model(frame_model &model, const scale_request &request);

error_code rotate_model(frame_model &model, const rotate_request &request);

error_code del_model(frame_model &model);

#endif 
