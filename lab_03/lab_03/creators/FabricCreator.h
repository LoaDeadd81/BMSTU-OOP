#ifndef FABRICCREATOR_H
#define FABRICCREATOR_H

#include "Drawer.h"

class FabricCreator
{
public:
    virtual ~FabricCreator() = 0;
    virtual shared_ptr<BaseDrawerFactory> create() = 0;
};

class QtFabricCreator : public FabricCreator
{
public:
    virtual ~QtFabricCreator() override =default;
    virtual shared_ptr<BaseDrawerFactory> create() override;
};

#endif
