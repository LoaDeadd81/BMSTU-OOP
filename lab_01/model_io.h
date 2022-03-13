#ifndef MODEL_IO_H
#define MODEL_IO_H

#include <cstdio>

#include "model.h"
#include "erorrs.h"


typedef struct read_request
{
    const char *file_name;
} read_request;

error_code input_model(model &figure, read_request& request);

#endif 
