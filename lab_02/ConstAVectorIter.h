#ifndef CONSTAVECTORITER_H
#define CONSTAVECTORITER_H

#include <memory>
#include <iterator>

#include "Error.h"
#include "BaseVectorIter.h"
#include "AVector.hpp"

//todo последовательность спецификаторов доступа
template<typename Type>
class ConstAVectorIter : public BaseVectorIter, public iterator<bidirectional_iterator_tag, Type>
{
public:
    ConstAVectorIter() = default;
    explicit ConstAVectorIter(const AVector<Type> &vec);
    ConstAVectorIter(const AVector<Type> &vec, size_t index);
    ConstAVectorIter(const ConstAVectorIter<Type> &iter);
    virtual ~ConstAVectorIter() = default;

    const Type* operator->() const;
    const Type& operator*() const;
    operator  bool() const;

    //todo операторы члены класса
    ConstAVectorIter<Type> &operator=(const ConstAVectorIter<Type> &iter);

    ConstAVectorIter<Type> &operator++();
    ConstAVectorIter<Type> operator++(int);

    ConstAVectorIter<Type> &operator--();
    ConstAVectorIter<Type> operator--(int);

    bool operator==(const ConstAVectorIter<Type> &iter) const;
    bool operator!=(const ConstAVectorIter<Type> &iter) const;
private:
    weak_ptr<Type[]> ptr;

    void check_data(string funk, int line) const;
    void check_index(string funk, int line) const;
};

#endif
