#include "ConstAVectorIter.h"

#ifndef CONSTAVECTORITER_HPP
#define CONSTAVECTORITER_HPP

template<typename Type>
void ConstAVectorIter<Type>::check_data(string funk, int line) const
{
    if (ptr.expired())
    {
        time_t t_time = time(NULL);
        throw MemoryError(__FILE__, funk, line, ctime(&t_time), "The data pointed to by the iterator is not available");
    }
}

template<typename Type>
void ConstAVectorIter<Type>::check_index(string funk, int line) const
{
    if (index < 0 || index >= count)
    {
        time_t t_time = time(NULL);
        throw IterIndexError(__FILE__, funk, line, ctime(&t_time), "Iterator out of range");
    }
}

template<typename Type>
ConstAVectorIter<Type>::ConstAVectorIter(const AVector<Type> &vec) : BaseVectorIter(vec.count)
{
    ptr = vec.data;
}

template<typename Type>
ConstAVectorIter<Type>::ConstAVectorIter(const AVector<Type> &vec, size_t index) : BaseVectorIter(vec.count, index)
{
    ptr = vec.data;
}

template<typename Type>
ConstAVectorIter<Type>::ConstAVectorIter(const ConstAVectorIter<Type> &iter) : BaseVectorIter(iter.count, iter.index)
{
    ptr = iter.ptr;
}

template<typename Type>
const Type *ConstAVectorIter<Type>::operator->() const
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return &tmp[index];
}

template<typename Type>
const Type &ConstAVectorIter<Type>::operator*() const
{
    check_data(__FUNCTION__ , __LINE__);
    check_index(__FUNCTION__ , __LINE__);

    shared_ptr<Type[]> tmp = ptr.lock();
    return tmp[index];
}

template<typename Type>
ConstAVectorIter<Type>::operator bool() const
{
    return !ptr.expired();
}

template<typename Type>
ConstAVectorIter<Type> &ConstAVectorIter<Type>::operator=(const ConstAVectorIter<Type> &iter)
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
ConstAVectorIter<Type> &ConstAVectorIter<Type>::operator++()
{
    index += 1;
    return *this;
}

template<typename Type>
ConstAVectorIter<Type> ConstAVectorIter<Type>::operator++(int)
{
    ConstAVectorIter<Type> res(*this);
    index += 1;
    return res;
}

template<typename Type>
ConstAVectorIter<Type> &ConstAVectorIter<Type>::operator--()
{
    index -= 1;
    return *this;
}

template<typename Type>
ConstAVectorIter<Type> ConstAVectorIter<Type>::operator--(int)
{
    ConstAVectorIter<Type> res(*this);
    index -= 1;
    return res;
}

template<typename Type>
bool ConstAVectorIter<Type>::operator==(const ConstAVectorIter<Type> &iter) const
{
    return this->ptr.lock() == iter.ptr.lock() && index == iter.index;
}

template<typename Type>
bool ConstAVectorIter<Type>::operator!=(const ConstAVectorIter<Type> &iter) const
{
    return !(*this == iter);
}


#endif