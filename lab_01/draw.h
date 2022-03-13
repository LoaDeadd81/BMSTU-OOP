#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>
#include <QPen>

#include "model.h"
#include "erorrs.h"

typedef struct draw_request
{
    QGraphicsScene *scene;
} draw_request;

error_code draw_model(model &figure, draw_request &request);
#endif 
