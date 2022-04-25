#ifndef BASEVECTORITER_H
#define BASEVECTORITER_H

#include <cstdlib>

//todo последовательность спецификаторов доступа
class BaseVectorIter
{
public:
    BaseVectorIter() = default;
    explicit BaseVectorIter(size_t size) : count(size) {};
    explicit BaseVectorIter(size_t size, size_t index) : index(index), count(size) {};

    virtual ~BaseVectorIter() = default;

protected:
    int index = 0;
    int count = 0;
};

#endif
