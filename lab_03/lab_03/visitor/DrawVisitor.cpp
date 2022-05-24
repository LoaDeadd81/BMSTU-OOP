#include "DrawVisitor.h"

DrawVisitor::DrawVisitor(shared_ptr<BaseDrawer> drawer, shared_ptr<Camera> camera) : drawer(drawer), camera(camera)
{

}

void DrawVisitor::visit(FrameModelImp &model)
{
    vector<Dot> dots = model.getDots();
    for(auto it = model.EdgeBegin(); it != model.EdgeEnd(); it++)
    {
        Coord3d start = get_progection(dots[it->getp1()], *camera), end = get_progection(dots[it->getp2()], *camera);
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

Coord3d DrawVisitor::get_progection(Dot point, Camera &cam)
{
    Coord3d move_data(-cam.pos.getX(), -cam.pos.getY(), -cam.pos.getZ()),
    rotate_data(-cam.dir.getX(), -cam.dir.getY(), -cam.dir.getZ());
    point.move(move_data);
    point.rotate(cam.pos, rotate_data);
    return point.getDot();
}
