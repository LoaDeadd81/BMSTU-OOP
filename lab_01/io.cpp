#include "io.h"

error_code input(frame_model &model, const input_request &request)
{
    return input_model(model, request.filename);
}
