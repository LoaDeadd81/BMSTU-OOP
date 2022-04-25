#ifndef LIBSCENE_H
#define LIBSCENE_H

#include "Point.h"
#include "ErrorType.h"

#include <QGraphicsScene>

typedef struct lib_scene
{
    QGraphicsScene *scene;
} lib_scene;

bool is_exist(lib_scene &scene);

error_code clean(lib_scene &scene);

error_code draw_line_lib(lib_scene &scene, const point_type &start, const point_type &end);

#endif 
