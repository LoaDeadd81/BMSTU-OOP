#ifndef SCENEINTERFACE_H
#define SCENEINTERFACE_H

#include "BaseScene.h"
#include "BaseCommand.h"

class SceneInterface
{
public:
    SceneInterface() = default;
    explicit SceneInterface(shared_ptr<BaseScene> scene) : scene(scene) {};
    void execute(shared_ptr<BaseCommand> command) {command->execute(scene);};
private:
    shared_ptr<BaseScene> scene;
};

#endif
