#include "draw.h"

error_code draw(draw_request &request, const frame_model &model)
{
    //todo обёртка для рисования
    return draw_model(request.scene, model);
}


