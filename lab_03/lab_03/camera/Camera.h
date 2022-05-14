#ifndef CAMERA_H
#define CAMERA_H

#include "InvisibleObject.h"
#include "Coord.h"

class BaseCamera : public InvisibleObjects
{
public:
    BaseCamera() = default;
    BaseCamera(const Coord3d &position,const Coord3d &direction) : pos(position), dir(direction) {};
    virtual ~BaseCamera() override = default;
    virtual bool isViewer() const override {return true;};
    Coord3d getPos() const {return pos;};
    Coord3d getDir() const {return dir;};
    void setPos(Coord3d &position) {pos = position;};
    void setDir(Coord3d &direction) {dir = direction;};
protected:
    Coord3d pos, dir;
};

class Camera : public BaseCamera
{
public:
    Camera() = default;
    Camera(const Coord3d &position,const Coord3d &direction) : BaseCamera(position, direction) {};
    virtual ~Camera() override = default;
    virtual void accept(const ObjectVisitor &visitor) override;
};

#endif
