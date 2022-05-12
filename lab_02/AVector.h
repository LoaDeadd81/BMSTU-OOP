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
    explicit AVector(const AVector<Type> &vector);
    AVector(AVector<Type> &&vector) noexcept;
    AVector(const Type *arr, size_t size);
    AVector(size_t size, Type elem, ...);
    AVector(const Type &elem, size_t size);
    AVector(initializer_list<Type> init_list);
    template<typename Iter>
    AVector(const Iter begin, const Iter end);
    template<typename Iter>
    AVector(const Iter begin, size_t size);

    virtual size_t size() const override;
    virtual bool empty() const override;
    virtual ~AVector() = default;

    //todo [] и at для const векторов
    Type &operator[](int i);
    Type &at(int i);
    const Type &operator[](int i) const;
    const Type &at(int i) const;

    Type &set(Type val, int i);

    //todo операторы члены класса
    AVector<Type> &operator=(const AVector<Type> &vec);
    AVector<Type> &operator=(AVector<Type> &&vec) noexcept;

    template<typename S>
    AVector<Type> &operator=(const AVector<S> &vec);

    template<typename S>
    AVector<Type> &operator+=(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &add(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &operator+=(const S &val);
    template<typename S>
    AVector<Type> &add(const S &val);

    template<typename S>
    AVector<Type> &operator-=(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &sub(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &operator-=(const S &val);
    template<typename S>
    AVector<Type> &sub(const S &val);

    template<typename S>
    AVector<Type> &operator*=(const S &val);
    template<typename S>
    AVector<Type> &mult(const S &val);
    template<typename S>
    AVector<Type> &operator*=(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &mult(const AVector<S> &vec);

    template<typename S>
    AVector<Type> &operator/=(const S &val);
    template<typename S>
    AVector<Type> &div(const S &val);
    template<typename S>
    AVector<Type> &operator/=(const AVector<S> &vec);
    template<typename S>
    AVector<Type> &div(const AVector<S> &vec);

    AVector<Type> operator-() const;

    template<class S>
    decltype(auto) operator+(const AVector<S> &vec) const;
    template<class S>
    static decltype(auto) add(const AVector<Type> &vec1, const AVector<S> &vec2);
    template<class S>
    decltype(auto) operator+(const S &val) const;
    template<class S>
    static decltype(auto) add(const AVector<Type> &vec, const S &val);

    template<class S>
    decltype(auto) operator-(const AVector<S> &vec) const;
    template<class S>
    static decltype(auto) sub(const AVector<Type> &vec1, const AVector<S> &vec2);
    template<class S>
    decltype(auto) operator-(const S &val) const;
    template<class S>
    static decltype(auto) sub(const AVector<Type> &vec, const S &val);

    template<class S>
    decltype(auto) operator*(const AVector<S> &vec) const;
    template<class S>
    static decltype(auto) mult(const AVector<Type> &vec1, const AVector<S> &vec2);
    template<class S>
    decltype(auto) operator*(const S &val) const;
    template<class S>
    static decltype(auto) mult(const AVector<Type> &vec, const S &val);

    template<class S>
    decltype(auto) operator/(const AVector<S> &vec) const;
    template<class S>
    static decltype(auto) div(const AVector<Type> &vec1, const AVector<S> &vec2);
    template<class S>
    decltype(auto) operator/(const S &val) const;
    template<class S>
    static decltype(auto) div(const AVector<Type> &vec, const S &val);

    template<typename S>
    decltype(auto) operator^(const AVector<S> &vec) const;
    template<typename S>
    static decltype(auto) scalar_mult(const AVector<Type> &vec1, const AVector<S> &vec2);

    template<typename S>
    decltype(auto) operator&(const AVector<S> &vec) const;
    template<typename S>
    static decltype(auto) vector_mult(const AVector<Type> &vec1, const AVector<S> &vec2);

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
    size_t len() const;
    AVector<Type> &clear();

    //todo геттеры для const векторов
    ConstAVectorIter<Type> cbegin() const;
    ConstAVectorIter<Type> cend() const;
    AVectorIter<Type> begin();
    AVectorIter<Type> end();
    ConstAVectorIter<Type> begin() const;
    ConstAVectorIter<Type> end() const;
private:
    shared_ptr<Type[]> data;

    void alloc(size_t size);
    void realloc(size_t size);
};

template<typename Type>
istream &operator>>(istream &is, const AVector<Type> &vec) ;

template<typename Type>
ostream &operator<<(ostream &os, const AVector<Type> &vec);

#endif
