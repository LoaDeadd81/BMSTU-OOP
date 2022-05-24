#include "DirectorSolution.h"

map<string, shared_ptr<ModelDirectorCreator>> ModelDirectorSolution::map;
shared_ptr<ModelDirectorCreator> ModelDirectorSolution::current;

void ModelDirectorSolution::registeraation(string name, shared_ptr<ModelDirectorCreator> creator)
{
    map.insert(make_pair(name, creator));
}

void ModelDirectorSolution::configure(string name)
{
    current = map[name];;
}

shared_ptr<ModelDirectorCreator> ModelDirectorSolution::get_creator()
{
    return current;
}

map<string, shared_ptr<CameraDirectorCreator>> CameraDirectorSolution::map;
shared_ptr<CameraDirectorCreator> CameraDirectorSolution::current;

void CameraDirectorSolution::registeraation(string name, shared_ptr<CameraDirectorCreator> creator)
{
    map.insert(make_pair(name, creator));
}

void CameraDirectorSolution::configure(string name)
{
    current = map[name];;
}

shared_ptr<CameraDirectorCreator> CameraDirectorSolution::get_creator()
{
    return current;
}
