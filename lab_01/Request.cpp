#include "Request.h"

error_code do_request(IN const request &action)
{
    static frame_model figure = init_model();
    error_code rc = SUCCESS;
    switch (action.type)
    {
        case INPUT:
            rc = input_model(figure, action.read);
            break;
        case DRAW:
            rc = draw_model(figure, action.draw);
            break;
        case MOVE:
            rc = move_model(figure, action.move);
            break;
        case SCALE:
            rc = scale_model(figure, action.scale);
            break;
        case ROTATE:
            rc = rotate_model(figure, action.rotate);
            break;
        case DEL:
            del_model(figure);
            break;
        default:
            rc = REQUEST_ERROR;
            break;
    }
    return rc;
}
