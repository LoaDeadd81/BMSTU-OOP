#include "draw.h"

error_code draw(frame_model &model, draw_request &request)
{
    return draw_model(model, request.scene);
}


