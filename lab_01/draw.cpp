#include "draw.h"

error_code draw_links(line_vector &line_vec, point_vector &point_vac, QGraphicsScene *scene);

error_code draw_line(point &start, point &end, QGraphicsScene *scene);

error_code draw_model(model &figure, draw_request &request)
{
    request.scene->clear();
    error_code rc = draw_links(figure.links, figure.points, request.scene);
    return rc;
}

error_code draw_links(line_vector &line_vec, point_vector &point_vac, QGraphicsScene *scene)
{
    error_code rc = SUCCESS;
    if (line_vec.arr == nullptr || point_vac.arr == nullptr)
        rc = DATA_ACCESS_ERROR;
    else
    {
        for (int i = 0; i < line_vec.len; i++)
        {
            point start = point_vac.arr[line_vec.arr[i].start_index],
                    end = point_vac.arr[line_vec.arr[i].end_index];
            draw_line(start, end, scene);
        }
    }
    return rc;
}

error_code draw_line(point &start, point &end, QGraphicsScene *scene)
{
//    scene->addLine(start.x + scene->width() / 2, -start.y + scene->height() / 2,
//                   end.x + scene->width() / 2, -end.y + scene->height() / 2);
    scene->addLine(start.x, -start.y, end.x , -end.y );
    return SUCCESS;
}
