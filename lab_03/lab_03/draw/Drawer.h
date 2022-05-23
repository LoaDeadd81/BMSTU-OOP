#ifndef DRAWER_H
#define DRAWER_H

#include "QtDrawTools.h"
#include "DrawTools.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    BaseDrawer(shared_ptr<BaseCanvas> canvas) : canvas(canvas) {};
    virtual ~BaseDrawer() = 0;
    virtual void set_canvas(shared_ptr<BaseCanvas> canvas) = 0;
    virtual void draw_line(double x1, double y1, double x2, double y2) = 0;
    virtual void clear() = 0;

protected:
    shared_ptr<BaseCanvas> canvas;
};

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;
    QtDrawer(shared_ptr<QtCanvas> canvas, shared_ptr<QtPen> pen, shared_ptr<QtBrush> brush);
    virtual ~QtDrawer() override = default;
    virtual void set_canvas(shared_ptr<BaseCanvas> canvas) override;
    virtual void draw_line(double x1, double y1, double x2, double y2) override;
    virtual void clear() override;
//private:
//    shared_ptr<QtPen> pen;
//    shared_ptr<QtBrush> brush;
};

class BaseDrawerFactory
{
public:
    virtual ~BaseDrawerFactory() = default;
//    virtual shared_ptr<BasePen> create_pen(Color &color, int width) = 0;
//    virtual shared_ptr<BaseBrush> create_brush(Color &color) = 0;
    virtual shared_ptr<BaseDrawer> create_drawer(shared_ptr<BaseCanvas> canvas, shared_ptr<BasePen> pen, shared_ptr<BaseBrush> brush) = 0;
};

class QtDrawerFactory : public BaseDrawerFactory
{
public:
    virtual ~QtDrawerFactory() override = default;
    virtual shared_ptr<BasePen> create_pen(Color &color, int width) override;
    virtual shared_ptr<BaseBrush> create_brush(Color &color) override;
    virtual shared_ptr<BaseDrawer> create_drawer(shared_ptr<BaseCanvas> canvas, shared_ptr<BasePen> pen, shared_ptr<BaseBrush> brush) override;
};


#endif
