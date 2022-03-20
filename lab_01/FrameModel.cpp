#include "FrameModel.h"

error_code input_tmp_model(frame_model &model, FILE *f);

error_code check_tmp_model(const frame_model &model);


frame_model init_model()
{
    points_type points = init_points();
    edges_type edges = init_edges();
    return {points, edges};
}

//var in model
error_code input_model(frame_model &model, const char *filename)
{
    frame_model tmp_model = init_model();
    FILE *f = fopen(filename, "r");
    error_code rc = SUCCESS;
    if (f == nullptr)
        rc = FILE_OPENING_ERROR;
    else
    {
        rc = input_tmp_model(tmp_model, f);
        fclose(f);
        if (rc == SUCCESS)
        {
            rc = check_tmp_model(tmp_model);
            if (rc == SUCCESS)
            {
                free_model(model);
                model = tmp_model;
            }
            else
                free_model(tmp_model);
        }
    }
    return rc;
}

error_code draw_model(QGraphicsScene *scene, const frame_model &model)
{
    error_code rc = SUCCESS;
    if(scene == nullptr)
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
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if(rc == SUCCESS)
    {
        rc = move_points(tmp_model.points, move_data);
        if(rc == SUCCESS)
        {
            free_model(model);
            model = tmp_model;
        }
        else
            free_model(tmp_model);
    }
    return rc;
}

error_code scale_model(frame_model &model, const point_type &center, const transform_data &scale_data)
{
    error_code rc = SUCCESS;
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if(rc == SUCCESS)
    {
        rc = scale_points(tmp_model.points, center, scale_data);
        if(rc == SUCCESS)
        {
            free_model(model);
            model = tmp_model;
        }
        else
            free_model(tmp_model);
    }
    return rc;
}

error_code rotate_model(frame_model &model, const point_type &center, const transform_data &rotate_data)
{
    error_code rc = SUCCESS;
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if(rc == SUCCESS)
    {
        rc = rotate_points(tmp_model.points, center, rotate_data);
        if(rc == SUCCESS)
        {
            free_model(model);
            model = tmp_model;
        }
        else
            free_model(tmp_model);
    }
    return rc;
}

error_code input_tmp_model(frame_model &model, FILE *f)
{
    error_code rc = SUCCESS;
    if(f == nullptr)
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
    }
    return rc;
}

error_code check_tmp_model(const frame_model &model)
{
    error_code rc = check_edges(model.edges, len(model.points));
    return rc;
}

error_code deep_copy(frame_model &dst, const frame_model &src)
{
    error_code rc = deep_copy(dst.points, src.points);
    if(rc == SUCCESS)
    {
        rc = deep_copy(dst.edges, src.edges);
        if(rc != SUCCESS)
            free_points(dst.points);
    }
    return rc;
}



void free_model(frame_model &model)
{
    free_points(model.points);
    free_edges(model.edges);
}
