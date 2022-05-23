#include "QtDrawTools.h"

QtCanvas::QtCanvas(shared_ptr<QGraphicsScene> scene) : scene(scene)
{

}

QtCanvas::QtCanvas(const QtCanvas &canvas)
{
    scene = canvas.scene;
}

void QtCanvas::draw_line(double x1, double y1, double x2, double y2)
{
    scene->addLine(x1, y1, x2, y2);
}

void QtCanvas::clear()
{

}

shared_ptr<QGraphicsScene> QtCanvas::get_scene() const
{
    return scene;
}

//QtPen::QtPen(Color &color, int width) : BasePen(color, width)
//{
//    QColor tmp_color(color.get_r(), color.get_g(), color.get_b());
//    pen = QPen(tmp_color);
//    pen.setWidth(width);
//}
//
//void QtPen::set_color(Color &color)
//{
//    QColor tmp_color(color.get_r(), color.get_g(), color.get_b());
//    pen.setColor(tmp_color);
//}
//
//void QtPen::set_width(int width)
//{
//    pen.setWidth(width);
//}
//
//QPen QtPen::get_pen()
//{
//    return pen;
//}
//
//QtBrush::QtBrush(Color &color) : BaseBrush(color)
//{
//    brush = QBrush();
//    QColor tmp_color(color.get_r(), color.get_g(), color.get_b());
//    brush.setColor(tmp_color);
//}
//
//void QtBrush::set_color(Color &color)
//{
//    QColor tmp_color(color.get_r(), color.get_g(), color.get_b());
//    brush.setColor(tmp_color);
//}
//
//QBrush QtBrush::get_brush()
//{
//    return brush;
//}
