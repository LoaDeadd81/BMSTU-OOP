#include "LibScene.h"

bool is_exist(lib_scene &scene)
{
    return scene.scene != nullptr;
}

error_code clean(lib_scene &scene)
{
    error_code rc = SUCCESS;
    if(scene.scene == nullptr)
        rc = ACCESS_ERROR;
    else
        scene.scene->clear();
    return rc;
}

error_code draw_line_lib(lib_scene &scene, const point_type &start, const point_type &end)
{
    error_code rc = SUCCESS;
    if(scene.scene == nullptr)
        rc = ACCESS_ERROR;
    else
        scene.scene->addLine(start.x, -start.y, end.x, -end.y);
    return rc;
}
