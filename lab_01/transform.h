#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "ErrorType.h"
#include "FrameModel.h"

typedef struct move_request
{
    transform_data move_data;
} move_request;

typedef struct scale_request
{
    point_type center;
    transform_data scale_data;
} scale_request;

typedef struct rotate_request
{
    point_type center;
    transform_data rotate_data;
} rotate_request;

error_code move(frame_model &model, const move_request &request);

error_code scale(frame_model &model, const scale_request &request);

error_code rotate(frame_model &model, const rotate_request &request);

#endif 
