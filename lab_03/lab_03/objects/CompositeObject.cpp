#include "CompositeObject.h"

bool CompositeObject::isVisible() const
{
    return false;
}

bool CompositeObject::isComposite() const
{
    return true;
}

bool CompositeObject::isViewer() const
{
    return false;
}

void CompositeObject::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

list<shared_ptr<SceneObject>>::iterator CompositeObject::begin()
{
    return objects.begin();
}

list<shared_ptr<SceneObject>>::iterator CompositeObject::end()
{
    return objects.end();
}

size_t CompositeObject::get_size() const
{
    return objects.size();
}

void CompositeObject::addObject(shared_ptr<SceneObject> &obj)
{
    objects.push_back(obj);
}

void CompositeObject::removeObject(list<shared_ptr<SceneObject>>::iterator iter)
{
    objects.erase(iter);
}