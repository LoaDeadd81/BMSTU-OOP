#include "io.h"

error_code input(frame_model &model, const input_request &request)
{
    frame_model tmp_model = init_model();
    error_code rc = input_model(tmp_model, request.filename);
    if(rc == SUCCESS)
    {
        rc = check_model(tmp_model);
        if (rc == SUCCESS)
            asigne(model, tmp_model);
        else
            free_model(tmp_model);
    }
    return rc;
}
