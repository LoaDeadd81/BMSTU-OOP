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

void CompositeObject::move(const Coord3d &transform_data)
{
    for (auto &it: objects) it->move(transform_data);
}

void CompositeObject::rotate(const Coord3d &transform_data, const Coord3d &center)
{
    for (auto &it: objects) it->rotate(transform_data, center);
}

void CompositeObject::scale(const Coord3d &transform_data, const Coord3d &center)
{
    for (auto &it: objects) it->scale(transform_data, center);
}
