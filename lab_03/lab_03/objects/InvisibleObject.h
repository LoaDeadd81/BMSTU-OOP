#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "Objects.h"

using namespace std;

class ObjectVisitor;

class InvisibleObjects : public Object
{
public:
    virtual ~InvisibleObjects() override = default;
}
#endif
