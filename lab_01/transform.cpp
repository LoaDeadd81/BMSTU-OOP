#include "transform.h"

error_code move(frame_model &model, const move_request &request)
{
    return move_model(model, request.move_data);
}

error_code scale(frame_model &model, const scale_request &request)
{
    return scale_model(model, request.center, request.scale_data);
}

error_code rotate(frame_model &model, const rotate_request &request)
{
    return rotate_model(model, request.center, request.rotate_data);
}
