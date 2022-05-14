#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <vector>

#include "Coord.h"

using namespace std;

class ObjectVisitor;

//todo change scheme
class Dot
{
public:
    Dot()=default;
    explicit Dot(Coord3d &coord3D) : pos(coord3D) {};
    ~Dot()=default;
    void setDot(const Coord3d &dot);
    Coord3d getDot() const;
    //todo accept
    void accept(ObjectVisitor &visitor);
protected:
    Coord3d pos;
};

//todo change scheme
class Edge
{
public:
    Edge()=default;
    explicit Edge(vector<Dot>::iterator start, vector<Dot>::iterator end) : p1(start), p2(end) {};
    ~Edge()=default;
    void setp1(const vector<Dot>::iterator dot);
    void setp2(const vector<Dot>::iterator dot);
    vector<Dot>::iterator getp1() const;
    vector<Dot>::iterator getp2() const;
    //todo accept
    void accept(ObjectVisitor &visitor);
protected:
    vector<Dot>::iterator p1, p2;
};

#endif
