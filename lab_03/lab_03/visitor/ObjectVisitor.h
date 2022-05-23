#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

class FrameModelImp;
class CameraImp;
class CompositeObject;


class ObjectVisitor
{
public:
    virtual ~ObjectVisitor() = default;
    virtual void visit(FrameModelImp &model) = 0;
    virtual void visit(CameraImp &camera) = 0;
    virtual void visit(CompositeObject &object) = 0;
};

#endif
