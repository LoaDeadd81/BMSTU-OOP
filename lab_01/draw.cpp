#include "draw.h"

error_code draw_line(const point_type &start, const point_type &end, QGraphicsScene *scene)
{
    scene->addLine(start.x, -start.y, end.x , -end.y );
}
