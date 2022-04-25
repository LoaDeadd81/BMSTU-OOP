#include "AVectorIter.h"

#ifndef AVECTORITER_HPP
#define AVECTORITER_HPP

template<typename Type>
void AVectorIter<Type>::check_data(string funk, int line) const
{
    if (ptr.expired()) throw MemoryError(__FILE__, funk, line, "The data pointed to by the iterator is not available");
}

template<typename Type>
void AVectorIter<Type>::check_index(string funk, int line) const
{
    if (index < 0 || index >= count) throw IterIndexError(__FILE__, funk, line, "Iterator out of range");
}

template<typename Type>
AVectorIter<Type>::AVectorIter(const AVector<Type> &vec) : BaseVectorIter(vec.count)
{
    ptr = vec.data;
}

template<typename Type>
AVectorIter<Type>::AVectorIter(const AVector<Type> &vec, size_t index) : BaseVectorIter(vec.count, index)
{
    ptr = vec.data;
}

template<typename Type>
AVectorIter<Type>::AVectorIter(const AVectorIter<Type> &iter) : BaseVectorIter(iter.count, iter.index)
{
    ptr = iter.ptr;
}

template<typename Type>
const Type *AVectorIter<Type>::operator->() const
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return &tmp[index];
}

template<typename Type>
const Type &AVectorIter<Type>::operator*() const
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return tmp[index];
}

template<typename Type>
Type *AVectorIter<Type>::operator->()
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return &tmp[index];
}

template<typename Type>
Type &AVectorIter<Type>::operator*()
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return tmp[index];
}

template<typename Type>
AVectorIter<Type>::operator bool() const
{
    return !ptr.expired();
}

template<typename Type>
AVectorIter<Type> &AVectorIter<Type>::operator=(const AVectorIter<Type> &iter)
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    ptr.reset();
    index = iter.index;
    count = iter.count;
    ptr = iter.ptr;
    return *this;
}

template<typename Type>
AVectorIter<Type> &AVectorIter<Type>::operator+=(int i)
{
    index += i;
    return *this;
}

template<typename Type>
AVectorIter<Type> &AVectorIter<Type>::operator-=(int i)
{
    index -= i;
    return *this;
}

template<typename Type>
AVectorIter<Type> AVectorIter<Type>::operator-(int i)
{
    AVectorIter<Type> res(*this);
    return res -= i;
}

template<typename Type>
AVectorIter<Type> &AVectorIter<Type>::operator++()
{
    index += 1;
    return *this;
}

template<typename Type>
AVectorIter<Type> AVectorIter<Type>::operator++(int)
{
    AVectorIter<Type> res(*this);
    index += 1;
    return res;
}

template<typename Type>
AVectorIter<Type> &AVectorIter<Type>::operator--()
{
    index -= 1;
    return *this;
}

template<typename Type>
AVectorIter<Type> AVectorIter<Type>::operator--(int)
{
    AVectorIter<Type> res(*this);
    index -= 1;
    return res;
}

template<typename Type>
bool AVectorIter<Type>::operator==(const AVectorIter<Type> &iter) const
{
    return index == iter.index;
}

template<typename Type>
bool AVectorIter<Type>::operator!=(const AVectorIter<Type> &iter) const
{
    return !(*this == iter);
}

template<typename Type>
bool AVectorIter<Type>::operator<(const AVectorIter<Type> &iter) const
{
    return index < iter.index;
}

template<typename Type>
bool AVectorIter<Type>::operator>(const AVectorIter<Type> &iter) const
{
    return index > iter.index;
}

template<typename Type>
bool AVectorIter<Type>::operator<=(const AVectorIter<Type> &iter) const
{
    return *this == iter || *this < iter;
}

template<typename Type>
bool AVectorIter<Type>::operator>=(const AVectorIter<Type> &iter) const
{
    return *this == iter || *this > iter;
}

template<typename Type>
AVectorIter<Type> operator+(const AVectorIter<Type> &iter, int i)
{
    AVectorIter<Type> res(iter);
    return res += i;
}

template<typename Type>
AVectorIter<Type> operator+(int i, const AVectorIter<Type> &iter)
{
    AVectorIter<Type> res(iter);
    return res += i;
}

#endif