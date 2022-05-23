#include "QtToolCreators.h"

shared_ptr<BaseCanvas> QtCanvasCreator::create(shared_ptr<QGraphicsScene> scene)
{
    shared_ptr<BaseCanvas> canvas = make_shared<QtCanvas>(scene);
    return canvas;
}

shared_ptr<BasePen> QtPenCreator::create(Color &color, int width)
{
    shared_ptr<BasePen> pen = make_shared<QtPen>(color, width);
    return pen;
}

shared_ptr<BaseBrush> QtBrushCreator::create(Color &color)
{
    shared_ptr<BaseBrush> brush = make_shared<QtBrush>(color);
    return brush;
}
