#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include "Point.h"
#include "Edge.h"
#include "ErrorType.h"
#include "LibScene.h"

#include <cstdio>

typedef struct frame_model
{
    points_type points;
    edges_type edges;
} frame_model;

frame_model init_model();

void free_model(frame_model &model);

error_code input_model(frame_model &model, const char *filename);

error_code check_model(const frame_model &model);

error_code draw_model(lib_scene &scene, const frame_model &model);

error_code move_model(frame_model &model, const transform_data &move_data);

error_code scale_model(frame_model &model, const point_type &center, const transform_data &scale_data);

error_code rotate_model(frame_model &model, const point_type &center, const transform_data &rotate_data);

error_code deep_copy(frame_model &dst, const frame_model &src);

void asigne(frame_model &dst, const frame_model &src);

#endif 
