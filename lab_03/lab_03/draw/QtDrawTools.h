#ifndef QTDRAWTOOLS_H
#define QTDRAWTOOLS_H

#include "DrawTools.h"
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QColor>

using namespace std;

class QtCanvas : public BaseCanvas
{
public:
    QtCanvas() = default;
    QtCanvas(shared_ptr<QGraphicsScene> scene);
    QtCanvas(const QtCanvas &canvas);
    virtual ~QtCanvas() override = default;
    virtual void draw_line(double x1, double y1, double x2, double y2) override;
    virtual void clear() override;
    shared_ptr<QGraphicsScene> get_scene() const;
private:
    shared_ptr<QGraphicsScene> scene;
};

//class QtPen : public BasePen
//{
//public:
//    QtPen() = default;
//    QtPen(Color &color, int width);
//    virtual ~QtPen() override = default;
//    virtual void set_color(Color &color) override;
//    virtual void set_width(int width) override;
//    QPen get_pen();
//private:
//    QPen pen;
//};
//
//class QtBrush : public BaseBrush
//{
//public:
//    QtBrush() = default;
//    QtBrush(Color &color);
//    virtual ~QtBrush() override = default;
//    virtual void set_color(Color &color) override;
//    QBrush get_brush();
//private:
//    QBrush brush;
//};

#endif
