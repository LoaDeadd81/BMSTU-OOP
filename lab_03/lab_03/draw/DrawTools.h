#ifndef DRAWTOOLS_H
#define DRAWTOOLS_H

#include <cstdlib>

class Color
{
public:
    Color() = default;
    Color(int r, int g, int b) : r(r), g(g), b(b) {};
    int get_r() {return r;};
    int get_g() {return g;};
    int get_b() {return b;};
private:
    int r, g, b;
};

class BaseCanvas
{
public:
    virtual ~BaseCanvas() = 0;
    virtual void draw_line(double x1, double y1, double x2, double y2) = 0;
    virtual void clear() = 0;
};

class BasePen
{
public:
    BasePen() = default;
    BasePen(Color &color, int width) : color(color), width(width) {};
    virtual void set_color(Color &color) =0;
    virtual void set_width(int width)=0;
    virtual ~BasePen() = 0;
protected:
    Color color;
    int width;
};

class BaseBrush
{
public:
    BaseBrush() = default;
    explicit BaseBrush(Color &color) : color(color) {};
    virtual void set_color(Color &color)=0;
    virtual ~BaseBrush() = 0;
protected:
    Color color;
};
#endif
