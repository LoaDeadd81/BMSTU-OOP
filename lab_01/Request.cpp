#include "Request.h"

error_code do_request(request &action)
{
    static frame_model model = init_model();
    error_code rc = SUCCESS;
    switch (action.type)
    {
        case INPUT:
            rc = input(model, action.read);
            break;
        case DRAW:
            rc = draw( action.draw, model);
            break;
        case MOVE:
            rc = move(model, action.move);
            break;
        case SCALE:
            rc = scale(model, action.scale);
            break;
        case ROTATE:
            rc = rotate(model, action.rotate);
            break;
        case DEL:
            free_model(model);
            break;
        default:
            rc = REQUEST_ERROR;
            break;
    }
    return rc;
}
