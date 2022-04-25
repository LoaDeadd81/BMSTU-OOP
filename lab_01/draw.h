#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "LibScene.h"

#include "FrameModel.h"
#include "ErrorType.h"

typedef struct draw_request
{
    lib_scene scene;
} draw_request;

error_code draw(draw_request &request, const frame_model &model);


#endif
