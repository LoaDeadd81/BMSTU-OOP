#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include "VisibleObjects.h"
#include "primitives.h"

class ModelImp
{
public:
    virtual ~ModelImp() = default;
    virtual void accept(ObjectVisitor &visitor) = 0;
};

class Model : public VisibleObjects
{
public:
    Model()=default;
    virtual ~Model() override = default;
    virtual void accept(ObjectVisitor &visitor) = 0;
};

class FrameModelImp : public ModelImp
{
public:
    FrameModelImp()=default;
    FrameModelImp(vector<Dot> &dots, vector<Edge> &edges);
    virtual ~FrameModelImp() override = default;
    virtual void accept(ObjectVisitor &visitor) override;
    vector<Dot>::iterator DotBegin();
    vector<Dot>::iterator  DotEnd();
    vector<Edge>::iterator  EdgeBegin();
    vector<Edge>::iterator  EdgeEnd();
private:
    vector<Dot> dots;
    vector<Edge> edges;
};

class FrameModel : public Model
{
public:
    FrameModel()=default;
    virtual ~FrameModel() override = default;
    virtual void accept(ObjectVisitor &visitor) override {imp->accept(visitor);}
    vector<Dot>::iterator DotBegin() {return imp->DotBegin();};
    vector<Dot>::iterator  DotEnd() {return imp->DotEnd();};
    vector<Edge>::iterator  EdgeBegin() {return imp->EdgeBegin();};
    vector<Edge>::iterator  EdgeEnd() {return imp->EdgeEnd();};
protected:
    shared_ptr<FrameModelImp> imp;
};

#endif
