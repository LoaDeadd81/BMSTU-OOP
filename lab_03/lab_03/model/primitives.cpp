#include "primitives.h"

void Dot::setDot(const Coord3d &dot)
{
    pos = dot;
}

Coord3d Dot::getDot() const
{
    return pos;
}

void Edge::setp1(const vector<Dot>::iterator dot)
{
    p1 = dot;
}

void Edge::setp2(const vector<Dot>::iterator dot)
{
    p2 = dot;
}

vector<Dot>::iterator Edge::getp1() const
{
    return p1;
}

vector<Dot>::iterator Edge::getp2() const
{
    return p2;
}


