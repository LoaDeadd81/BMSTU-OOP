#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include "ObjectVisitor.h"
#include "Coord.h"

class TransformVisitor : public ObjectVisitor
{
public:
    TransformVisitor()=default;
    explicit TransformVisitor(const Coord3d &transform_data) : data(transform_data) {};
    virtual ~TransformVisitor() override = default;
protected:
    Coord3d data;
};

class MoveVisitor : public TransformVisitor
{
public:
    MoveVisitor()=default;
    explicit MoveVisitor(const Coord3d &transform_data) : TransformVisitor(transform_data) {};
    virtual ~MoveVisitor() override = default;
    virtual void visit(FrameModel &model) override;
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(Composite &composite) override;
};

class RotateVisitor : public TransformVisitor
{
public:
    RotateVisitor()=default;
    explicit RotateVisitor(const Coord3d &transform_data) : TransformVisitor(transform_data) {};
    virtual ~RotateVisitor() override = default;
    virtual void visit(FrameModel &model) override;
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(Composite &composite) override;
};

class ScaleVisitor : public TransformVisitor
{
public:
    ScaleVisitor()=default;
    explicit ScaleVisitor(const Coord3d &transform_data) : TransformVisitor(transform_data) {};
    virtual ~ScaleVisitor() override = default;
    virtual void visit(FrameModel &model) override;
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(Composite &composite) override;
};

#endif
