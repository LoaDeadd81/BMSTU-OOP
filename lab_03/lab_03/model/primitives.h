#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <memory>

#include "ObjectVisitor.h"
#include "Coord.h"

using namespace std;

class Dot
{
public:
    Dot()=default;
    explicit Dot(Coord3d &coord3D) : pos(coord3D) {};
    ~Dot()=default;
    void setDot(const Coord3d &dot);
    Coord3d getDot() const;
    void move(const Coord3d &transform_data);
    void rotate(const Coord3d &center, const Coord3d &transform_data);
    void scale(const Coord3d &center, const Coord3d &transform_data);
    void accept(shared_ptr<ObjectVisitor> visitor);
protected:
    Coord3d pos;
};

//todo change scheme
class Edge
{
public:
    Edge()=default;
    explicit Edge(size_t start, size_t end) : p1(start), p2(end) {};
    ~Edge()=default;
    void setp1(size_t dot);
    void setp2(size_t dot);
    size_t getp1() const;
    size_t getp2() const;
    void accept(shared_ptr<ObjectVisitor> visitor);
protected:
    size_t p1, p2;
};

#endif
