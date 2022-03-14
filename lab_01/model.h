#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "line.h"

typedef struct model
{
    point_vector points;
    line_vector links;
} model;

model init_model();

void del_model(model &figure);

void reinit_model(model &figure);

bool is_model_exist(model &figure);


#endif 
