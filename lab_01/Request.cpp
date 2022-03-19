#include "Request.h"

error_code do_request(request &action)
{
    static frame_model figure = init_model();
    error_code rc = SUCCESS;
    switch (action.type)
    {
        case INPUT:
            rc = input(figure, action.read);
            break;
        case DRAW:
            rc = draw(figure, action.draw);
            break;
        case MOVE:
            rc = move(figure, action.move);
            break;
        case SCALE:
            rc = scale(figure, action.scale);
            break;
        case ROTATE:
            rc = rotate(figure, action.rotate);
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
