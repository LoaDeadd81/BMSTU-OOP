#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>

#include "SimpleObject.h"
#include "primitives.h"

class BaseModelImp
{
public:
    virtual ~BaseModelImp() = 0;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) = 0;
};

class BaseModel : public VisibleObject
{
public:
    BaseModel()=default;
    explicit BaseModel(shared_ptr<BaseModelImp> imp) : imp(imp) {};
    virtual ~BaseModel() override = default;
protected:
    shared_ptr<BaseModelImp> imp;
};

class FrameModelImp : public BaseModelImp
{
public:
    FrameModelImp()=default;
    FrameModelImp(vector<Dot> &dots, vector<Edge> &edges);
    virtual ~FrameModelImp() override = default;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override;
    vector<Dot>::iterator DotBegin();
    vector<Dot>::iterator DotEnd();
    vector<Edge>::iterator EdgeBegin();
    vector<Edge>::iterator EdgeEnd();
    vector<Dot> &getDots();
    vector<Edge> &getEdges();
private:
    vector<Dot> dots;
    vector<Edge> edges;
};

class FrameModel : public BaseModel
{
public:
    FrameModel()=default;
    explicit FrameModel(shared_ptr<BaseModelImp> imp) : BaseModel(imp) {};
    virtual ~FrameModel() override = default;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override {imp->accept(visitor);}

};

#endif
