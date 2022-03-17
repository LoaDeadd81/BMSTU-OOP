#ifndef REQUEST_H
#define REQUEST_H

#include "ErrorType.h"
#include "FrameModel.h"
#include "RequestTypes.h"

enum request_type
{
    INPUT, DRAW, MOVE, SCALE, ROTATE, DEL
};

struct request
{
    request_type type;
    union
    {
        input_request read;
        draw_request draw;
        move_request move;
        scale_request scale;
        rotate_request rotate;
    };
};



error_code do_request(const request &action);

#endif 
