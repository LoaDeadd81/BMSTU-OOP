#include "Camera.h"

void Camera::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

Coord3d Camera::getPos() const
{
    return pos;
}

Coord3d Camera::getDir() const
{
    return dir;
}

void Camera::setPos(Coord3d &position)
{
    pos = position;
}

void Camera::setDir(Coord3d &direction)
{
    dir = direction;
}

bool Camera::isViewer() const
{
    return true;
}

void Camera::move(const Coord3d &transform_data)
{
    double new_x = pos.getX() + transform_data.getX(),
            new_y = pos.getY() + transform_data.getY(),
            new_z = pos.getZ() + transform_data.getZ();
    pos = {new_x, new_y, new_z};
}

void Camera::rotate(const Coord3d &transform_data, const Coord3d &center)
{
    double new_x = fmod(dir.getX() + transform_data.getX(), 360),
            new_y = fmod(dir.getY() + transform_data.getY(), 360),
            new_z = fmod(dir.getZ() + transform_data.getZ(), 360);
    dir = {new_x, new_y, new_z};
}

void Camera::scale(const Coord3d &transform_data, const Coord3d &center)
{

}


