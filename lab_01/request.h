#ifndef REQUEST_H
#define REQUEST_H

#include "model_io.h"
#include "draw.h"
#include "transformation.h"
#include "erorrs.h"
#include "model.h"

enum request_type
{
    READ_DATA, DRAW, MOVE, SCALE, ROTATE, DEL
};

struct request
{
    request_type type;
    union
    {
        read_request read;
        draw_request draw;
        move_request move;
        scale_request scale;
        rotate_request rotate;
    };
};

error_code do_request(request &action);

#endif 
