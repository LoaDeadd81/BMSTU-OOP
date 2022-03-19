#ifndef IO_H
#define IO_H

#include <cstdio>

#include "FrameModel.h"
#include "ErrorType.h"

typedef struct input_request
{
    const char *filename;
} input_request;

error_code input(frame_model &model, const input_request &request);

#endif 
