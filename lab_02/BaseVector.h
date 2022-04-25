#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include <cstdlib>

//todo последовательность спецификаторов доступа
class BaseVector
{
public:
    BaseVector() = default;
    explicit BaseVector(size_t size = 0) : count(size) {};

    virtual size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual ~BaseVector() = default;
protected:
    size_t count = 0;

};

#endif
