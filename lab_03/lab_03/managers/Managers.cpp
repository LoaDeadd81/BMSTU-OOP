#include "Managers.h"

AddObjectManager::AddObjectManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void AddObjectManager::execute(shared_ptr<SceneObject> obj)
{
    scene->add_object(obj);
}

DelObjectManager::DelObjectManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void DelObjectManager::execute(size_t i)
{
    //todo check errors
    scene->del_object(i);
}

ChangeCameraManager::ChangeCameraManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void ChangeCameraManager::execute(size_t i)
{
    //todo check errors
    scene->set_cam(i);
}

DrawManager::DrawManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void DrawManager::execute(shared_ptr<BaseDrawer> drawer)
{

}

MoveManager::MoveManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void MoveManager::execute(size_t i, const Coord3d &data)
{
    //todo check errors
    auto it = scene->begin();
    for (int j = 0; j < i; j++, it++);
    shared_ptr<ObjectVisitor> visitor = MoveVisitorCreator().create(data);
    (*it)->accept(visitor);
}

RotateManager::RotateManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void RotateManager::execute(size_t i, const Coord3d &data, const Coord3d &center)
{
//todo check errors
    auto it = scene->begin();
    for (int j = 0; j < i; j++, it++);
    shared_ptr<ObjectVisitor> visitor = RotateVisitorCreator().create(data);
    (*it)->accept(visitor);
}

ScaleManager::ScaleManager(shared_ptr<BaseScene> scene) : BaseManager(scene)
{

}

void ScaleManager::execute(size_t i, const Coord3d &data, const Coord3d &center)
{
    //todo check errors
    auto it = scene->begin();
    for (int j = 0; j < i; j++, it++);
    shared_ptr<ObjectVisitor> visitor = RotateVisitorCreator().create(data);
    (*it)->accept(visitor);
}
