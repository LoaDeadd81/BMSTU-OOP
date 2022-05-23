#ifndef COMPOSITEOBJEXT_H
#define COMPOSITEOBJEXT_H

#include "SceneObjects.h"

class CompositeObject : public SceneObject
{
public:
    CompositeObject() = default;
    virtual ~CompositeObject() override = default;

    virtual bool isVisible() const override;
    virtual bool isComposite() const override;
    virtual bool isViewer() const override;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override;

    virtual list<shared_ptr<SceneObject>>::iterator begin() override;
    virtual list<shared_ptr<SceneObject>>::iterator end() override;
    virtual size_t get_size() const override;
    virtual void addObject(shared_ptr<SceneObject> &obj) override;
    virtual void removeObject(list<shared_ptr<SceneObject>>::iterator iter) override;
private:
    list<shared_ptr<SceneObject>> objects;
};

#endif