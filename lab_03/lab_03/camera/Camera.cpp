#include "Camera.h"

Coord3d CameraImp::getPos() const
{
    return pos;
}

Coord3d CameraImp::getDir() const
{
    return dir;
}

void CameraImp::setPos(Coord3d &position)
{
    pos = position;
}

void CameraImp::setDir(Coord3d &direction)
{
    dir = direction;
}


