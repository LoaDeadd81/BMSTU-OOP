#ifndef AVECTORITER_H
#define AVECTORITER_H

#include <memory>
#include <iterator>

#include "Error.h"
#include "BaseVectorIter.h"
#include "AVector.hpp"

//todo последовательность спецификаторов доступа
//todo операторы в класс
template<typename Type>
class AVectorIter : public BaseVectorIter, public iterator<bidirectional_iterator_tag, Type>
{
public:
    AVectorIter() = default;
    explicit AVectorIter(const AVector<Type> &vec);
    AVectorIter(const AVector<Type> &vec, size_t index);
    AVectorIter(const AVectorIter<Type> &iter);
    virtual ~AVectorIter() = default;

    //todo операторы для константных итераторов
    const Type* operator->() const;
    const Type& operator*() const;
    Type* operator->();
    Type& operator*();
    explicit operator  bool() const;

    AVectorIter<Type> &operator=(const AVectorIter<Type> &iter);

    AVectorIter<Type> &operator+=(int i);

    AVectorIter<Type> &operator-=(int i);

    AVectorIter<Type> operator-(int i);

    AVectorIter<Type> &operator++();
    AVectorIter<Type> operator++(int);

    AVectorIter<Type> &operator--();
    AVectorIter<Type> operator--(int);

    bool operator==(const AVectorIter<Type> &iter) const;
    bool operator!=(const AVectorIter<Type> &iter) const;

    bool operator<(const AVectorIter<Type> &iter) const;
    bool operator>(const AVectorIter<Type> &iter) const;

    bool operator<=(const AVectorIter<Type> &iter) const;
    bool operator>=(const AVectorIter<Type> &iter) const;
private:
    weak_ptr<Type[]> ptr;

    void check_data(string funk, int line) const;
    void check_index(string funk, int line) const;
};

template<typename Type>
AVectorIter<Type> operator+(const AVectorIter<Type> &iter, int i);
template<typename Type>
AVectorIter<Type> operator+(int i, const AVectorIter<Type> &iter);

#endif
