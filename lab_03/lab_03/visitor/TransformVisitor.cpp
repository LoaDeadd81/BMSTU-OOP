#include "TransformVisitor.h"

MoveVisitor::MoveVisitor(const Coord3d &data) : TranformVisitor(data)
{

}

void MoveVisitor::visit(FrameModelImp &model)
{
    for (auto i = model.DotBegin(); i != model.DotEnd(); i++) i->move(data);
}

void MoveVisitor::visit(Camera &camera)
{
    camera.move(data);
}

void MoveVisitor::visit(CompositeObject &object)
{
    shared_ptr<ObjectVisitor> tmp_ptr(this);
    for (auto i = object.begin(); i != object.end(); i++) object.accept(tmp_ptr);
}

RotateVisitor::RotateVisitor(const Coord3d &data, const Coord3d &center) : TranformVisitor(data, center)
{

}

void RotateVisitor::visit(FrameModelImp &model)
{
    for (auto i = model.DotBegin(); i != model.DotEnd(); i++) i->rotate(center, data);
}

void RotateVisitor::visit(Camera &camera)
{
    camera.rotate(data);
}

void RotateVisitor::visit(CompositeObject &object)
{
    shared_ptr<ObjectVisitor> tmp_ptr(this);
    for (auto i = object.begin(); i != object.end(); i++) object.accept(tmp_ptr);
}

ScaleVisitor::ScaleVisitor(const Coord3d &data, const Coord3d &center) : TranformVisitor(data, center)
{

}

void ScaleVisitor::visit(FrameModelImp &model)
{
    for (auto i = model.DotBegin(); i != model.DotEnd(); i++) i->scale(center, data);
}

void ScaleVisitor::visit(Camera &camera)
{
}

void ScaleVisitor::visit(CompositeObject &object)
{
    shared_ptr<ObjectVisitor> tmp_ptr(this);
    for (auto i = object.begin(); i != object.end(); i++) object.accept(tmp_ptr);
}



