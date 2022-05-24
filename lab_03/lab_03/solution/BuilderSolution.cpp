#include "BuilderSolution.h"

map<string, shared_ptr<ModelBuilderCreator>> ModelBuilderSolution::map;
shared_ptr<ModelBuilderCreator> ModelBuilderSolution::current;

void ModelBuilderSolution::registeraation(string name, shared_ptr<ModelBuilderCreator> creator)
{
    map.insert(make_pair(name, creator));
}

void ModelBuilderSolution::configure(string name)
{
    current = map[name];;
}

shared_ptr<ModelBuilderCreator> ModelBuilderSolution::get_creator()
{
    return current;
}

map<string, shared_ptr<CameraBuilderCreator>> CameraBuilderSolution::map;
shared_ptr<CameraBuilderCreator> CameraBuilderSolution::current;

void CameraBuilderSolution::registeraation(string name, shared_ptr<CameraBuilderCreator> creator)
{
    map.insert(make_pair(name, creator));
}

void CameraBuilderSolution::configure(string name)
{
    current = map[name];;
}

shared_ptr<CameraBuilderCreator> CameraBuilderSolution::get_creator()
{
    return current;
}
