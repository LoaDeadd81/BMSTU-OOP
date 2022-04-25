#include "transform.h"

error_code move(frame_model &model, const move_request &request)
{
    error_code rc = SUCCESS;
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if (rc == SUCCESS)
    {
        rc = move_model(tmp_model, request.move_data);
        if (rc == SUCCESS)
            asigne(model, tmp_model);
        else
            free_model(tmp_model);
    }
    return rc;
}

error_code scale(frame_model &model, const scale_request &request)
{
    error_code rc = SUCCESS;
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if (rc == SUCCESS)
    {
        rc = scale_model(tmp_model, request.center, request.scale_data);
        if (rc == SUCCESS)
            asigne(model, tmp_model);
        else
            free_model(tmp_model);
    }
    return rc;
}

error_code rotate(frame_model &model, const rotate_request &request)
{
    error_code rc = SUCCESS;
    frame_model tmp_model = init_model();
    rc = deep_copy(tmp_model, model);
    if (rc == SUCCESS)
    {
        rc = rotate_model(tmp_model, request.center, request.rotate_data);
        if (rc == SUCCESS)
            asigne(model, tmp_model);
        else
            free_model(tmp_model);
    }
    return rc;
}
