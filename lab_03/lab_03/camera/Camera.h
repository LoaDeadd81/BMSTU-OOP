#ifndef CAMERA_H
#define CAMERA_H

#include "SimpleObject.h"
#include "Coord.h"
#include <cmath>

class CameraBuilder;
class DrawVisitor;

class Camera : public InvisibleObject
{
    friend CameraBuilder;
    friend DrawVisitor;
public:
    Camera() = default;
    Camera(const Coord3d &position, const Coord3d &direction) : pos(position), dir(direction) {};
    virtual ~Camera() override = default;
    virtual bool isViewer() const override ;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override;
    virtual void move(const Coord3d &transform_data) override;
    virtual void rotate(const Coord3d &transform_data, const Coord3d &center = {0,0,0}) override;
    virtual void scale(const Coord3d &transform_data, const Coord3d &center = {0,0,0}) override;

private:
    Coord3d pos{}, dir{};

    Coord3d getPos() const;
    Coord3d getDir() const;
    void setPos(Coord3d &position);
    void setDir(Coord3d &direction);
};


#endif
