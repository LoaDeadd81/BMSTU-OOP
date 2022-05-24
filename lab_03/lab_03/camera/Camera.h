#ifndef CAMERA_H
#define CAMERA_H

#include "SimpleObject.h"
#include "Coord.h"

class DrawVisitor;
class MoveVisitor;
class RotateVisitor;
class CameraBuilder;

class Camera : public InvisibleObject
{
    friend DrawVisitor;
    friend MoveVisitor;
    friend RotateVisitor;
    friend CameraBuilder;
public:
    Camera() = default;
    Camera(const Coord3d &position, const Coord3d &direction) : pos(position), dir(direction) {};
    virtual ~Camera() override = default;
    virtual bool isViewer() const override ;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override;

private:
    Coord3d pos{}, dir{};

    Coord3d getPos() const;
    Coord3d getDir() const;
    void setPos(Coord3d &position);
    void setDir(Coord3d &direction);
    void move(const Coord3d &transform_data);
    void rotate(const Coord3d &transform_data);
};


#endif
