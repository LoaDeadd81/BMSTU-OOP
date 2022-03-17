#include "FrameModel.h"

error_code input_tmp_model(frame_model &model, const FILE *f);
error_code check_tmp_model(const frame_model &model);
void free_model(frame_model &model);

frame_model init_model()
{
    points_type points = init_points();
    edges_type edges = init_edges();
    return {points, edges};
}

error_code input_model(frame_model &model, const input_request &request)
{
    frame_model tmp_model = init_model();

    FILE *f = fopen(request.filename, "r");
    error_code ec = SUCCESS;
    if(f == nullptr)
        ec = FILE_OPENING_ERROR;
    else
    {
        ec = input_tmp_model(tmp_model, f);
        fclose(f);
        if(ec == SUCCESS)
        {
            ec = check_tmp_model(tmp_model);
            if (ec == SUCCESS)
            {
                free_model(model);
                model = tmp_model;
            }
            else
                free_model(model);
        }
    }
    return ec;
}

error_code draw_model(frame_model &model, draw_request &request)
{
    request.scene->clear();
    error_code ec = draw_edges(model.edges, request.scene);
    return ec;
}

error_code move_model(frame_model &model, const move_request &request)
{
    error_code ec = move_points(model.points, request.move_data);
    return ec;
}

error_code scale_model(frame_model &model, const scale_request &request)
{
    error_code ec = scale_points(model.points, request.center, request.scale_data);
    return ec;
}

error_code rotate_model(frame_model &model, const rotate_request &request)
{
    error_code ec = rotate_points(model.points, request.center, request.rotate_data);
    return ec;
}

error_code del_model(frame_model &model)
{
    free_model(model);
}

error_code input_tmp_model(frame_model &model, const FILE *f)
{
    error_code ec = input_points(model.points, f);
    if(ec == SUCCESS)
    {
        ec = input_edges(model.edges, f);
        if (ec != SUCCESS)
            free_edges(model.edges);
    }
    else
        free_points(model.points);
    return ec;
}

error_code check_tmp_model(const frame_model &model)
{
    error_code ec = check_edges(model.edges, model.edges.len);
    return ec;
}

void free_model(frame_model &model)
{
    free_points(model.points);
    free_edges(model.edges);
}
