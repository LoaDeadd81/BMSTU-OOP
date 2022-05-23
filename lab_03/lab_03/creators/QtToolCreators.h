#ifndef QTTOOLCREATORS_H
#define QTTOOLCREATORS_H

#include "QtDrawTools.h"

class QtCanvasCreator
{
public:
    shared_ptr<BaseCanvas> create(shared_ptr<QGraphicsScene> scene);
};

class QtPenCreator
{
public:
    shared_ptr<BasePen> create(Color &color, int width);
};

class QtBrushCreator
{
public:
    shared_ptr<BaseBrush> create(Color &color);
};

#endif
