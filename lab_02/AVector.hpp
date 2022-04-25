#include "AVector.h"

#ifndef AVECTOR_HPP
#define AVECTOR_HPP

#define EPS 1e-4

double to_degree(double rad)
{
    return rad * (180.0 / M_PI);
}

double to_radians(double degree)
{
    return degree * (M_PI / 180.0);
}

template<typename Type>
void check_size(string funk, int line, const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    if (vec1.size() != vec2.size())
        throw DimensionError(__FILE__, funk, line,
                             "The dimensions of the operands do not match");
}

template<typename Type>
void AVector<Type>::alloc(size_t size)
{
    data = shared_ptr<Type[]>(new Type[size]);
    if (!data) throw MemoryError(__FILE__, __FUNCTION__, __LINE__, "Failed to allocate memory");
}

template<typename Type>
void AVector<Type>::realloc(size_t size)
{
    data.reset();
    data = shared_ptr<Type[]>(new Type[count]);
    if (!data) throw MemoryError(__FILE__, __FUNCTION__, __LINE__, "Failed to allocate memory");
}

template<typename Type>
AVector<Type>::AVector(size_t size) : BaseVector(size)
{
    alloc(size);
}

template<typename Type>
AVector<Type>::AVector(const AVector<Type> &vector) : BaseVector(vector.count)
{
    alloc(count);
    for (int i = 0; i < count; i++) data[i] = vector.data[i];
}

template<typename Type>
AVector<Type>::AVector(AVector<Type> &&vector) noexcept: BaseVector(vector.count)
{
    data = vector.data;
    vector.data.reset();
}

template<typename Type>
AVector<Type>::AVector(const Type *arr, size_t size) : BaseVector(size)
{
    alloc(size);
    for (int i = 0; i < count; i++) data[i] = arr[i];
}

template<typename Type>
AVector<Type>::AVector(size_t size, Type elem, ...) : BaseVector(size)
{
    alloc(size);
    va_list args;
    va_start(args, elem);
    for (int i = 0; i < size; i++) data[i] = va_arg(args, Type);
    va_end(args);
}

template<typename Type>
AVector<Type>::AVector(const Type &elem, size_t size) : BaseVector(size)
{
    alloc(size);
    for (int i = 0; i < size; i++) data[i] = elem;
}

template<typename Type>
AVector<Type>::AVector(initializer_list<Type> init_list) : BaseVector(init_list.size())
{
    alloc(init_list.size());
    auto it = init_list.begin();
    for (int i = 0; i < init_list.size(); i++) data[i] = *(it++);
}

template<typename Type>
size_t AVector<Type>::size() const
{
    return count;
}

template<typename Type>
bool AVector<Type>::empty() const
{
    return false;
}

template<typename Type>
Type &AVector<Type>::operator[](int i)
{
    if (i < 0 || i >= count) throw IndexError(__FILE__, __FUNCTION__, __LINE__, "Index out of range");
    return data[i];
}

template<typename Type>
Type &AVector<Type>::at(int i)
{
    return data[i];
}

template<typename Type>
const Type &AVector<Type>::operator[](int i) const
{
    if (i < 0) i += count;
    if (i >= count) throw IndexError(__FILE__, __FUNCTION__, __LINE__, "Index out of range");
    return data[i];
}

template<typename Type>
const Type &AVector<Type>::at(int i) const
{
    return data[i];
}

template<typename Type>
Type &AVector<Type>::set(Type val, int i)
{
    return data[i] = val;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator=(const AVector<Type> &vec)
{
    if (this == &vec)
        return *this;
    if (count != vec.count)
    {
        realloc(vec.count);
        count = vec.count;
    }
    for (int i = 0; i < count; i++) data[i] = vec.data[i];
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator=(AVector<Type> &&vec) noexcept
{
    if (this == &vec)
        return *this;
    count = vec.count;
    data.reset();
    data = vec.data;
    vec.data.reset();
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator+=(const AVector<Type> &vec)
{
    if (count != vec.count)
        throw DimensionError(__FILE__, __FUNCTION__, __LINE__, "The dimensions of the operands do not match");
    for (int i = 0; i < count; i++) data[i] += vec.data[i];
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::add(const AVector<Type> &vec)
{
    return *this += vec;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator+=(const Type &val)
{
    for (int i = 0; i < count; i++) data[i] += val;
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::add(const Type &val)
{
    return *this += val;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator-=(const AVector<Type> &vec)
{
    if (count != vec.count)
        throw DimensionError(__FILE__, __FUNCTION__, __LINE__, "The dimensions of the operands do not match");
    for (int i = 0; i < count; i++) data[i] -= vec.data[i];
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::sub(const AVector<Type> &vec)
{
    return *this -= vec;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator-=(const Type &val)
{
    for (int i = 0; i < count; i++) data[i] -= val;
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::sub(const Type &val)
{
    return *this -= val;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator*=(const Type &val)
{
    for (int i = 0; i < count; i++) data[i] *= val;
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::mult(const Type &val)
{
    return *this *= val;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator*=(const AVector<Type> &vec)
{
    if (count != vec.count)
        throw DimensionError(__FILE__, __FUNCTION__, __LINE__, "The dimensions of the operands do not match");
    for (int i = 0; i < count; i++) data[i] *= vec.data[i];
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::mult(const AVector<Type> &vec)
{
    return *this *= vec;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator/=(const Type &val)
{
    if (val == Type(0)) throw ZeroDivError(__FILE__, __FUNCTION__, __LINE__, "Zero division");
    for (int i = 0; i < count; i++) data[i] /= val;
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::div(const Type &val)
{
    return *this /= val;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator/=(const AVector<Type> &vec)
{
    if (count != vec.count)
        throw DimensionError(__FILE__, __FUNCTION__, __LINE__, "The dimensions of the operands do not match");
    for (int i = 0; i < count; i++)
    {
        if (vec.data[i] == Type(0)) throw ZeroDivError(__FILE__, __FUNCTION__, __LINE__, "Zero division");
        data[i] /= vec.data[i];
    }
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::div(const AVector<Type> &vec)
{
    return *this /= vec;
}

template<typename Type>
AVector<Type> AVector<Type>::operator-() const
{
    AVector<Type> res(*this);
    for (int i = 0; i < count; i++) res[i] = -res[i];
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::operator+(const AVector<Type> &vec) const
{
    AVector<Type> res = *this;
    res += vec;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::add(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 + vec2;
}

template<typename Type>
AVector<Type> AVector<Type>::add(const AVector<Type> &vec, const Type &val)
{
    return vec + val;
}

template<typename Type>
AVector<Type> AVector<Type>::operator-(const AVector<Type> &vec) const
{
    AVector<Type> res = *this;
    res -= vec;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::sub(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 - vec2;
}

template<typename Type>
AVector<Type> AVector<Type>::operator-(const Type &val) const
{
    AVector<Type> res = *this;
    res -= val;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::sub(const AVector<Type> &vec, const Type &val)
{
    return vec - val;
}

template<typename Type>
AVector<Type> AVector<Type>::operator*(const AVector<Type> &vec) const
{
    AVector<Type> res = *this;
    res *= vec;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::mult(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 * vec2;
}

template<typename Type>
AVector<Type> AVector<Type>::mult(const AVector<Type> &vec, const Type &val)
{
    return vec * val;
}

template<typename Type>
AVector<Type> AVector<Type>::operator/(const AVector<Type> &vec) const
{
    AVector<Type> res = *this;
    res /= vec;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::div(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 / vec2;
}

template<typename Type>
AVector<Type> AVector<Type>::operator/(const Type &val) const
{
    AVector<Type> res = *this;
    res /= val;
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::div(const AVector<Type> &vec, const Type &val)
{
    return vec / val;
}

template<typename Type>
Type AVector<Type>::operator^(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    Type res = Type(0);
    for (int i = 0; i < this->size(); i++) res += data[i] * vec.data[i];
    return res;
}

template<typename Type>
Type AVector<Type>::scalar_mult(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 ^ vec2;
}

template<typename Type>
AVector<Type> AVector<Type>::operator&(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    if (count != 3)
        throw DimensionError(__FILE__, __FUNCTION__, __LINE__, "For a vector product , vectors of dimension 3 are needed");

    AVector<Type> res(3);
    res[0] = data[1] * vec.data[2] - data[2] * vec.data[1];
    res[1] = data[2] * vec.data[0] - data[0] * vec.data[2];
    res[2] = data[0] * vec.data[1] - data[1] * vec.data[0];
    return res;
}

template<typename Type>
AVector<Type> AVector<Type>::vector_mult(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    return vec1 & vec2;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator++()
{
    return *this += Type(1);
}

template<typename Type>
AVector<Type> AVector<Type>::operator++(int)
{
    AVector<Type> res = *this;
    *this += Type(1);
    return res;
}

template<typename Type>
AVector<Type> &AVector<Type>::operator--()
{
    return *this -= Type(1);
}

template<typename Type>
AVector<Type> AVector<Type>::operator--(int)
{
    AVector<Type> res = *this;
    *this -= Type(1);
    return res;
}

template<typename Type>
bool AVector<Type>::operator!=(const AVector<Type> &vec) const
{
    return !(*this == vec);
}

template<typename Type>
bool AVector<Type>::operator==(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    for (int i = 0; i < count; i++)
        if (data[i] != vec.data[i])
            return false;
    return true;
}

template<typename Type>
bool AVector<Type>::operator>(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    for (int i = 0; i < count; i++)
        if (data[i] <= vec.data[i])
            return false;
    return true;
}

template<typename Type>
bool AVector<Type>::operator<(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    for (int i = 0; i < count; i++)
        if (data[i] >= vec.data[i])
            return false;
    return true;
}

template<typename Type>
bool AVector<Type>::operator>=(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    for (int i = 0; i < count; i++)
        if (data[i] < vec.data[i])
            return false;
    return true;
}

template<typename Type>
bool AVector<Type>::operator<=(const AVector<Type> &vec) const
{
    check_size(__FILE__, __LINE__, *this, vec);
    for (int i = 0; i < count; i++)
        if (data[i] > vec.data[i])
            return false;
    return true;
}

template<typename Type>
int AVector<Type>::cmp(const AVector<Type> &vec1, const AVector<Type> &vec2)
{
    if (vec1 == vec2)
        return 0;
    if (vec1 > vec2)
        return 1;
    else
        return -1;
}

template<typename Type>
double AVector<Type>::angle_between(const AVector<Type> &vec) const
{
    double cos_val = (*this ^ vec) / (this->len() * vec.len());
    return to_degree(acos(cos_val));
}

template<typename Type>
bool AVector<Type>::is_collinear(const AVector<Type> &vec) const
{
    double rad = to_radians(this->angle_between(vec));
    return fabs(sin(rad)) < EPS;
}

template<typename Type>
bool AVector<Type>::is_orthogonal(const AVector<Type> &vec) const
{
    double rad = to_radians(this->angle_between(vec));
    return fabs(cos(rad)) < EPS;
}

template<typename Type>
AVector<Type> &AVector<Type>::neg()
{
    for (int i = 0; i < count; i++) data[i] = -data[i];
    return *this;
}

template<typename Type>
AVector<Type> &AVector<Type>::norm()
{
    Type coef = Type(0);
    for (int i = 0; i < count; i++) coef += data[i] * data[i];
    coef = sqrt(coef);
    return *this /= coef;
}

template<typename Type>
Type AVector<Type>::len() const
{
    Type coef = 0;
    for (int i = 0; i < count; i++) coef += data[i] * data[i];
    coef = sqrt(coef);
    return coef;
}

template<typename Type>
AVector<Type> &AVector<Type>::clear()
{
    for (int i = 0; i < count; i++) data[i] = Type(0);
    return *this;
}

template<typename Type>
ConstAVectorIter<Type> AVector<Type>::cbegin() const
{
    return ConstAVectorIter<Type>(*this);
}

template<typename Type>
ConstAVectorIter<Type> AVector<Type>::cend() const
{
    return ConstAVectorIter<Type>(*this, count);
}

template<typename Type>
ConstAVectorIter<Type> AVector<Type>::begin() const
{
    return ConstAVectorIter<Type>(*this);
}

template<typename Type>
ConstAVectorIter<Type> AVector<Type>::end() const
{
    return ConstAVectorIter<Type>(*this, count);
}

template<typename Type>
AVectorIter<Type> AVector<Type>::begin()
{
    return AVectorIter<Type>(*this);
}

template<typename Type>
AVectorIter<Type> AVector<Type>::end()
{
    return AVectorIter<Type>(*this, count);
}

template<typename Type>
AVector<Type> operator+(const Type &val, const AVector<Type> &vec)
{
    AVector<Type> res = vec;
    return res += val;
}

template<typename Type>
AVector<Type> operator+(const AVector<Type> &vec, const Type &val)
{
    AVector<Type> res = vec;
    return res += val;
}

template<typename Type>
AVector<Type> operator*(const Type &val, const AVector<Type> &vec)
{
    AVector<Type> res = vec;
    return res *= val;
}

template<typename Type>
AVector<Type> operator*(const AVector<Type> &vec, const Type &val)
{
    AVector<Type> res = vec;
    return res *= val;
}

template<typename Type>
istream &operator>>(istream &is, const AVector<Type> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}

template<typename Type>
ostream &operator<<(ostream &os, const AVector<Type> &vec)
{
    os << "( ";
    for (int i = 0; i < vec.size(); i++)
    {
        os << vec[i];
        if (i != vec.size() - 1)
            os << ", ";
    }
    os << ")";
    return os;
}

#endif
