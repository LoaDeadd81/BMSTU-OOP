#ifndef AVECTOR_H
#define AVECTOR_H

#include <initializer_list>
#include <iterator>
#include <cstdarg>
#include <iostream>
#include <cmath>

#include "BaseVector.h"
#include "Error.h"

template<typename Type> class ConstAVectorIter;
template<typename Type> class AVectorIter;

//todo последовательность спецификаторов доступа
template<typename Type>
class AVector : public BaseVector
{
    friend ConstAVectorIter<Type>;
    friend AVectorIter<Type>;
public:
    //Конструкторы
    AVector() = default;

    explicit AVector(size_t size);

    AVector(const AVector<Type> &vector);

    AVector(AVector<Type> &&vector) noexcept;

    AVector(const Type *arr, size_t size);

    AVector(size_t size, Type elem, ...);

    AVector(const Type &elem, size_t size);

    AVector(initializer_list<Type> init_list);

    AVector(const AVectorIter<Type> begin, const AVectorIter<Type> end);

    AVector(const AVectorIter<Type> begin, size_t size);

    AVector(const ConstAVectorIter<Type> begin, const ConstAVectorIter<Type> end);

    AVector(const ConstAVectorIter<Type> begin, size_t size);

    virtual size_t size() const override;

    virtual bool empty() const override;

    virtual ~AVector() = default;

    //todo [] для const векторов
    Type &operator[](int i);
    Type &at(int i);
    const Type &operator[](int i) const;
    const Type &at(int i) const;

    Type &set(Type val, int i);

    AVector<Type> &operator=(const AVector<Type> &vec);
    AVector<Type> &operator=(AVector<Type> &&vec) noexcept;

    AVector<Type> &operator+=(const AVector<Type> &vec);
    AVector<Type> &add(const AVector<Type> &vec);
    AVector<Type> &operator+=(const Type &val);
    AVector<Type> &add(const Type &val);

    AVector<Type> &operator-=(const AVector<Type> &vec);
    AVector<Type> &sub(const AVector<Type> &vec);
    AVector<Type> &operator-=(const Type &val);
    AVector<Type> &sub(const Type &val);

    AVector<Type> &operator*=(const Type &val);
    AVector<Type> &mult(const Type &val);
    AVector<Type> &operator*=(const AVector<Type> &vec);
    AVector<Type> &mult(const AVector<Type> &vec);

    AVector<Type> &operator/=(const Type &val);
    AVector<Type> &div(const Type &val);
    AVector<Type> &operator/=(const AVector<Type> &vec);
    AVector<Type> &div(const AVector<Type> &vec);

    AVector<Type> operator-() const;

    AVector<Type> operator+(const AVector<Type> &vec) const;
    static AVector<Type> add(const AVector<Type> &vec1, const AVector<Type> &vec2);
    static AVector<Type> add(const AVector<Type> &vec, const Type &val);

    AVector<Type> operator-(const AVector<Type> &vec) const;
    static AVector<Type> sub(const AVector<Type> &vec1, const AVector<Type> &vec2);
    AVector<Type> operator-(const Type &val) const;
    static AVector<Type> sub(const AVector<Type> &vec, const Type &val);

    AVector<Type> operator*(const AVector<Type> &vec) const;
    static AVector<Type> mult(const AVector<Type> &vec1, const AVector<Type> &vec2);
    static AVector<Type> mult(const AVector<Type> &vec, const Type &val);

    AVector<Type> operator/(const AVector<Type> &vec) const;
    static AVector<Type> div(const AVector<Type> &vec1, const AVector<Type> &vec2);
    AVector<Type> operator/(const Type &val) const;
    static AVector<Type> div(const AVector<Type> &vec, const Type &val);

    Type operator^(const AVector<Type> &vec) const;
    static Type scalar_mult(const AVector<Type> &vec1, const AVector<Type> &vec2);

    AVector<Type> operator&(const AVector<Type> &vec) const;
    static AVector<Type> vector_mult(const AVector<Type> &vec1, const AVector<Type> &vec2);

    AVector<Type> &operator++();
    AVector<Type> operator++(int);

    AVector<Type> &operator--();
    AVector<Type> operator--(int);

    bool operator!=(const AVector<Type> &vec) const;
    bool operator==(const AVector<Type> &vec) const;

    bool operator>(const AVector<Type> &vec) const;
    bool operator<(const AVector<Type> &vec) const;

    bool operator>=(const AVector<Type> &vec) const;
    bool operator<=(const AVector<Type> &vec) const;

    static int cmp(const AVector<Type> &vec1, const AVector<Type> &vec2);

    double angle_between(const AVector<Type> &vec) const;
    bool is_collinear(const AVector<Type> &vec) const;
    bool is_orthogonal(const AVector<Type> &vec) const;

    AVector<Type> &neg();
    AVector<Type> &norm();
    Type len() const;
    AVector<Type> &clear();

    //todo геттеры для const векторов
    ConstAVectorIter<Type> cbegin() const;
    ConstAVectorIter<Type> cend() const;
    AVectorIter<Type> begin();
    AVectorIter<Type> end();
    ConstAVectorIter<Type> begin() const;
    ConstAVectorIter<Type> end() const;
    //todo внести методы, операции в класс(оставить только для коммутативности)
private:
    shared_ptr<Type[]> data;

    void alloc(size_t size);
    void realloc(size_t size);
};

template<typename Type>
AVector<Type> operator+(const Type &val, const AVector<Type> &vec);
template<typename Type>
AVector<Type> operator+(const AVector<Type> &vec, const Type &val);

template<typename Type>
AVector<Type> operator*(const AVector<Type> &vec, const Type &val);
template<typename Type>
AVector<Type> operator*(const Type &val, const AVector<Type> &vec);

template<typename Type>
istream &operator>>(istream &is, const AVector<Type> &vec) ;

template<typename Type>
ostream &operator<<(ostream &os, const AVector<Type> &vec);

#endif
