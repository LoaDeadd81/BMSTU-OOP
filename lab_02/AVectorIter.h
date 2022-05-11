#ifndef AVECTORITER_H
#define AVECTORITER_H

#include <memory>
#include <iterator>

#include "Error.h"
#include "BaseVectorIter.h"
#include "AVector.hpp"

//todo последовательность спецификаторов доступа
template<typename Type>
class AVectorIter : public BaseVectorIter, public iterator<bidirectional_iterator_tag, Type>
{
public:
    AVectorIter() = default;
    explicit AVectorIter(const AVector<Type> &vec);
    AVectorIter(const AVector<Type> &vec, size_t index);
    AVectorIter(const AVectorIter<Type> &iter);
    virtual ~AVectorIter() = default;

    //todo * и -> для константных итераторов
    const Type* operator->() const;
    const Type& operator*() const;
    Type* operator->();
    Type& operator*();
    operator  bool() const;

    //todo операторы члены класса
    AVectorIter<Type> &operator=(const AVectorIter<Type> &iter);

    AVectorIter<Type> &operator++();
    AVectorIter<Type> operator++(int);

    AVectorIter<Type> &operator--();
    AVectorIter<Type> operator--(int);

    bool operator==(const AVectorIter<Type> &iter) const;
    bool operator!=(const AVectorIter<Type> &iter) const;
private:
    weak_ptr<Type[]> ptr;

    void check_data(string funk, int line) const;
    void check_index(string funk, int line) const;
};

#endif
