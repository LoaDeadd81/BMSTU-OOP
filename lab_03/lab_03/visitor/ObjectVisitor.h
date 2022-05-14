#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

#include "Model.h"
#include "Camera.h"

class ObjectVisitor
{
public:
    virtual ~ObjectVisitor()=default;
    virtual void visit(FrameModel &model) const = 0;
    virtual void visit(BaseCamera &camera) const = 0;
    virtual void visit(Composite &composite) = 0;
};

#endif
