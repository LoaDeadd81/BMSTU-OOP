#include "FrameModel.h"

frame_model init_model()
{
    points_type points = init_points();
    edges_type edges = init_edges();
    return {points, edges};
}

error_code input_model(frame_model &model, const char *filename)
{
    FILE *f = fopen(filename, "r");
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        rc = input_points(model.points, f);
        if (rc == SUCCESS)
        {
            rc = input_edges(model.edges, f);
            if (rc != SUCCESS)
                free_points(model.points);
        }
        fclose(f);
    }
    return rc;
}

error_code draw_model(QGraphicsScene *scene, const frame_model &model)
{
    error_code rc = SUCCESS;
    if (scene == nullptr)
        rc = ACCESS_ERROR;
    else
    {
        scene->clear();
        rc = draw_edges(scene, model.edges, model.points);
    }
    return rc;
}

error_code move_model(frame_model &model, const transform_data &move_data)
{
    error_code rc = SUCCESS;
    points_type tmp_points = init_points();
    rc = deep_copy(tmp_points, model.points);
    if (rc == SUCCESS)
    {
        rc = move_points(tmp_points, move_data);
        if (rc == SUCCESS)
            asigne(model.points, tmp_points);
        else
            free_points(tmp_points);
    }
    return rc;
}

error_code scale_model(frame_model &model, const point_type &center, const transform_data &scale_data)
{
    error_code rc = SUCCESS;
    points_type tmp_points = init_points();
    rc = deep_copy(tmp_points, model.points);
    if (rc == SUCCESS)
    {
        rc = scale_points(tmp_points, center, scale_data);
        if (rc == SUCCESS)
            asigne(model.points, tmp_points);
        else
            free_points(tmp_points);
    }
    return rc;
}

error_code rotate_model(frame_model &model, const point_type &center, const transform_data &rotate_data)
{
    error_code rc = SUCCESS;
    points_type tmp_points = init_points();
    rc = deep_copy(tmp_points, model.points);
    if (rc == SUCCESS)
    {
        rc = rotate_points(tmp_points, center, rotate_data);
        if (rc == SUCCESS)
            asigne(model.points, tmp_points);
        else
            free_points(tmp_points);
    }
    return rc;
}

error_code check_model(const frame_model &model)
{
    error_code rc = check_edges(model.edges, len(model.points));
    return rc;
}

error_code deep_copy(frame_model &dst, const frame_model &src)
{
    error_code rc = deep_copy(dst.points, src.points);
    if (rc == SUCCESS)
    {
        rc = deep_copy(dst.edges, src.edges);
        if (rc != SUCCESS)
            free_points(dst.points);
    }
    return rc;
}

void asigne(frame_model &dst, const frame_model &src)
{
    free_model(dst);
    dst = src;
}

void free_model(frame_model &model)
{
    free_points(model.points);
    free_edges(model.edges);
}
