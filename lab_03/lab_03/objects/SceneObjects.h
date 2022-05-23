#ifndef SCENEOBJECTS_H
#define SCENEOBJECTS_H

#include <list>
#include <initializer_list>
#include <memory>
#include "ObjectVisitor.h"

using namespace std;

class SceneObject
{
public:
    virtual ~SceneObject()=0;
    virtual bool isVisible() const = 0;
    virtual bool isComposite() const = 0;
    virtual bool isViewer() const = 0;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) = 0;
    virtual list<shared_ptr<SceneObject>>::iterator begin() {};
    virtual list<shared_ptr<SceneObject>>::iterator end() {};
    virtual size_t get_size() const {};
    virtual void addObject(shared_ptr<SceneObject> &obj) {};
    virtual void removeObject(list<shared_ptr<SceneObject>>::iterator iter) {};
};

#endif
