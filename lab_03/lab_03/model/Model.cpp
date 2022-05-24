#include "Model.h"

FrameModelImp::FrameModelImp(vector<Dot> &dots, vector<Edge> &edges) : dots(dots), edges(edges)
{

}

void FrameModelImp::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

vector<Dot>::iterator  FrameModelImp::DotBegin()
{
    return dots.begin();
}

vector<Dot>::iterator FrameModelImp::DotEnd()
{
    return dots.end();
}

vector<Edge>::iterator FrameModelImp::EdgeBegin()
{
    return edges.begin();
}

vector<Edge>::iterator FrameModelImp::EdgeEnd()
{
    return edges.end();
}

vector<Dot> &FrameModelImp::getDots()
{
    return dots;
}

vector<Edge> &FrameModelImp::getEdges()
{
    return edges;
}

void FrameModelImp::move(const Coord3d &transform_data)
{
    for (auto &it : dots) it.move(transform_data);
}

void FrameModelImp::rotate(const Coord3d &transform_data, const Coord3d &center)
{
    for (auto &it : dots) it.rotate(center, transform_data);
}

void FrameModelImp::scale(const Coord3d &transform_data, const Coord3d &center)
{
    for (auto &it : dots) it.scale(center, transform_data);
}

void FrameModel::move(const Coord3d &transform_data)
{
    imp->move(transform_data);
}

void FrameModel::rotate(const Coord3d &transform_data, const Coord3d &center)
{
    imp->rotate(transform_data, center);
}

void FrameModel::scale(const Coord3d &transform_data, const Coord3d &center)
{
    imp->scale(transform_data, center);
}
