#include "Objects.h"

Composite::Composite(const Composite &obj) : objects(obj.objects)
{

}

Composite::Composite(initializer_list<Object> init_list)
{
    for (auto &it: init_list) objects.push_back(it);
}

Composite &Composite::operator=(const Composite &obj)
{
    objects = obj.objects;
    return *this;
}

Object &Composite::operator[](int i)
{
    return objects[i];
}

const Object &Composite::operator[](int i) const
{
    return objects[i];
}

bool Composite::isComposite() const
{
    return true;
}

vector<Object>::iterator Composite::begin()
{
    return objects.begin();
}

vector<Object>::iterator Composite::end()
{
    return objects.end();
}

vector<Object>::const_iterator Composite::cbegin() const
{
    return objects.cbegin();
}

vector<Object>::const_iterator Composite::cend() const
{
    return objects.cend();
}

size_t Composite::get_size() const
{
    return objects.size();
}

void Composite::addObject(Object &obj)
{
    objects.push_back(obj);
}

void Composite::removeObject(vector<Object>::iterator iter)
{
    objects.erase(iter);
}

void Composite::accept(const ObjectVisitor &Visitor)
{
    Visitor.visit(*this);
}


