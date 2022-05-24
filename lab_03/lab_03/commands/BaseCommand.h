#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "BaseScene.h"

class BaseCommand
{
public:
    virtual ~BaseCommand() = default;
    virtual void execute(shared_ptr<BaseScene> scene) = 0;
};

#endif
