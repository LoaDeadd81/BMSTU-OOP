#ifndef CAMERA_H
#define CAMERA_H

#include "SimpleObject.h"
#include "Coord.h"

class BaseCameraImp
{
public:
    virtual ~BaseCameraImp() = 0;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) = 0;
protected:
    Coord3d pos, dir;
};

class BaseCamera : public VisibleObject
{
public:
    BaseCamera()=default;
    explicit BaseCamera(shared_ptr<BaseCameraImp> imp) : imp(imp) {};
    virtual ~BaseCamera() override = default;
    virtual bool isViewer() const override {return true;};
protected:
    shared_ptr<BaseCameraImp> imp;
};

class CameraImp : public BaseCameraImp
{
public:
    CameraImp() = default;
    CameraImp(const Coord3d &position, const Coord3d &direction) : pos(position), dir(direction) {};
    virtual ~CameraImp() override = default;
    Coord3d getPos() const;
    Coord3d getDir() const;
    void setPos(Coord3d &position);
    void setDir(Coord3d &direction);
    void move(const Coord3d &transform_data);
    void rotate(const Coord3d &transform_data);
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override;
};

class Camera : public BaseCamera
{
public:
    Camera()=default;
    explicit Camera(shared_ptr<BaseCameraImp> imp) : BaseCamera(imp) {};
    virtual ~Camera() override = default;
    virtual void accept(shared_ptr<ObjectVisitor> visitor) override {imp->accept(visitor);}

};


#endif
