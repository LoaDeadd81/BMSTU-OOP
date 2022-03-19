#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "FrameModel.h"
#include "ErrorType.h"

typedef struct draw_request
{
    QGraphicsScene *scene;
} draw_request;

error_code draw(frame_model &model, draw_request &request);



#endif 
