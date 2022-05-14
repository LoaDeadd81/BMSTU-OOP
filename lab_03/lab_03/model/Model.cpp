#include "Model.h"

FrameModelImp::FrameModelImp(vector<Dot> &dots, vector<Edge> &edges) : dots(dots), edges(edges)
{

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
