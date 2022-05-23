#include "DrawVisitor.h"

DrawVisitor::DrawVisitor(shared_ptr<BaseDrawer> drawer, shared_ptr<BaseCamera> camera) : drawer(drawer), camera(camera)
{

}

void DrawVisitor::visit(FrameModelImp &model)
{
    //todo проекция
    vector<Dot> dots = model.getDots();
    for(auto it = model.EdgeBegin(); it != model.EdgeEnd(); it++)
    {
        Coord3d start = dots[it->getp1()].getDot(), end = dots[it->getp2()].getDot();
        drawer->draw_line(start.getX(), start.getY(), end.getX(), end.getY());
    }
}

void DrawVisitor::visit(Camera &camera)
{

}

void DrawVisitor::visit(CompositeObject &object)
{
    shared_ptr<ObjectVisitor> tmp_ptr(dynamic_cast<ObjectVisitor*>(this));
    for (auto i = object.begin(); i != object.end(); i++) object.accept(tmp_ptr);
}
