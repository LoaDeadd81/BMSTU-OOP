#ifndef VISIBLEOBJECTS_H
#define VISIBLEOBJECTS_H

#include "Objects.h"

using namespace std;

class ObjectVisitor;

class VisibleObjects : public Object
{
public:
    virtual ~VisibleObjects() override = default;
    virtual bool isVisible() const override{ return true; };
};

#endif
