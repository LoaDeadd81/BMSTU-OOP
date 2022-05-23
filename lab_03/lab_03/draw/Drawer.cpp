#include "Drawer.h"

QtDrawer::QtDrawer(shared_ptr<QtCanvas> canvas, shared_ptr<QtPen> pen, shared_ptr<QtBrush> brush)
{
    ca
}

void QtDrawer::set_canvas(shared_ptr<BaseCanvas> canvas)
{
    this->canvas = canvas;
}

void QtDrawer::draw_line(double x1, double y1, double x2, double y2)
{
    canvas->get_scene()->addLine(x1, y1, x2, y2);
}

void QtDrawer::clear()
{
    canvas->get_scene()->clear();
}

shared_ptr<BasePen> QtDrawerFactory::create_pen(Color &color, int width)
{
    shared_ptr<BasePen> pen = make_shared<QtPen>(color, width);
    return pen;
}

shared_ptr<BaseBrush> QtDrawerFactory::create_brush(Color &color)
{
    shared_ptr<BaseBrush> brush = make_shared<QtBrush>(color);
    return brush;
}

shared_ptr<BaseDrawer>
QtDrawerFactory::create_drawer(shared_ptr<BaseCanvas> canvas, shared_ptr<BasePen> pen, shared_ptr<BaseBrush> brush)
{
    shared_ptr<BaseDrawer> drawer = make_shared<QtDrawer>(dynamic_pointer_cast<QtCanvas>(canvas),
                                                          dynamic_pointer_cast<QtPen>(pen),
                                                          dynamic_pointer_cast<QtBrush>(brush));
    return drawer;
}
