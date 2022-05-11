#include <iostream>
#include "AVector.hpp"
#include "ConstAVectorIter.hpp"
#include "AVectorIter.hpp"
#include <complex>
#include "Error.h"

using namespace std;

void check_constructors();

void check_methods();

void check_operators();

void check_extra_funcs();

void check_iteraotors();

void check_const_iteraotors();


int main()
{
//    check_constructors();
//    check_methods();
//    check_operators();
//    check_extra_funcs();
//    check_iteraotors();
//    check_const_iteraotors();

    AVector a = {1, 2, 3};
    AVector b = {complex(1), complex(2, 3), complex(4)};
    AVector c = {3.4, 2.2, 3.3};
    cout << a + c << endl;
    cout << a + complex(1, 3) << endl;
    a += c + c;
    cout << a << endl;
    return 0;
}

void check_constructors()
{
    cout << "Constructor test \nAll initialized by 1, 2, 3, 4, 5" << endl;

    int n = 5;
    cout << "int param" << endl;
    AVector<int> c1(n);
    for (int i = 0; i < n; i++) c1[i] = i + 1;
    cout << c1 << endl << endl;

    cout << "copy" << endl;
    AVector<int> c2(c1);
    cout << c2 << endl << endl;

    cout << "by array" << endl;
    int arr3[] = {1, 2, 3, 4, 5};
    AVector<int> c3(arr3, n);
    cout << c3 << endl << endl;

    cout << "by cstdarg" << endl;
    AVector<int> c4(5, 1, 1, 2, 3, 4, 5);
    cout << c4 << endl << endl;

    cout << "by one elem" << endl;
    AVector<int> c5(1, (size_t) 5);
    cout << c5 << endl << endl;

    cout << "by init list" << endl;
    AVector<int> c6 = {1, 2, 3, 4, 5};
    cout << c6 << endl << endl;

    cout << "by itearators" << endl;
    AVector<int> c7(c6.begin(), c6.end());
    cout << c7 << endl << endl;

    cout << "by itearator and size" << endl;
    AVector<int> c8(c6.begin(), c6.size());
    cout << c8 << endl << endl;
}

void check_methods()
{
    cout << "Methods test" << endl;

    cout << "assignment" << endl;
    AVector<int> c11 = {1, 2, 3, 4, 5, 6, 7}, c12 = {5, 4, 3, 2, 1};
    cout << "before: " << c11 << endl;
    cout << c11 << " = " << c12 << endl;
    c11 = c12;
    cout << "now: " << c11 << endl << endl;

    cout << "add" << endl;
    AVector<int> c21 = {1, 2, 3, 4, 5}, c22 = {5, 4, 3, 2, 1};
    cout << "before: " << c21 << endl;
    cout << c21 << " += " << c22 << endl;
    c21 += c22;
    cout << "now: " << c21 << endl << endl;

    cout << "add on scalar" << endl;
    AVector<int> c31 = {1, 2, 3, 4, 5};
    int c32 = 5;
    cout << "before: " << c31 << endl;
    cout << c31 << " += " << c32 << endl;
    c31 += c32;
    cout << "now: " << c31 << endl << endl;

    cout << "sub" << endl;
    AVector<int> c41 = {1, 2, 3, 4, 5}, c42 = {5, 4, 3, 2, 1};
    cout << "before: " << c41 << endl;
    cout << c41 << " -= " << c42 << endl;
    c41 -= c42;
    cout << "now: " << c41 << endl << endl;

    cout << "sub on scalar" << endl;
    AVector<int> c51 = {1, 2, 3, 4, 5};
    int c52 = 5;
    cout << "before: " << c51 << endl;
    cout << c51 << " -= " << c52 << endl;
    c51 -= c52;
    cout << "now: " << c51 << endl << endl;

    cout << "mult" << endl;
    AVector<double> c61 = {1, 2, 3, 4, 5}, c62 = {5, 4, 3, 2, 1};
    cout << "before: " << c61 << endl;
    cout << c61 << " *= " << c62 << endl;
    c61 *= c62;
    cout << "now: " << c61 << endl << endl;

    cout << "mult on scalar" << endl;
    AVector<double> c71 = {1, 2, 3, 4, 5};
    double c72 = 5;
    cout << "before: " << c71 << endl;
    cout << c71 << " *= " << c72 << endl;
    c71 *= c72;
    cout << "now: " << c71 << endl << endl;

    cout << "div" << endl;
    AVector<double> c81 = {1, 2, 3, 4, 5}, c82 = {5, 4, 3, 2, 1};
    cout << "before: " << c81 << endl;
    cout << c81 << " /= " << c82 << endl;
    c81 /= c82;
    cout << "now: " << c81 << endl << endl;

    cout << "div scalar" << endl;
    AVector<double> c91 = {1, 2, 3, 4, 5};
    double c92 = 5;
    cout << "before: " << c91 << endl;
    cout << c91 << " /= " << c92 << endl;
    c91 /= c92;
    cout << "now: " << c91 << endl << endl;

    cout << "neg" << endl;
    AVector<double> c101 = {1, 2, 3, 4, 5};
    cout << "before: " << c101 << endl;
    cout << " - " << c101 << endl;
    c101.neg();
    cout << "now: " << c101 << endl << endl;

    cout << "norm" << endl;
    AVector<double> c111 = {1, 1, 1, 1, 1};
    cout << "before: " << c111 << endl;
    c111.norm();
    cout << "now: " << c111 << endl << endl;

    cout << "len" << endl;
    AVector<double> c121 = {2, 2, 2, 2};
    cout << "vector: " << c121 << endl;
    cout << "len: " << c121.len() << endl << endl;

    cout << "clear" << endl;
    AVector<double> c131 = {2, 2, 2, 2};
    cout << "vector: " << c131 << endl;
    cout << "len: " << c131.clear() << endl << endl;
}

void check_operators()
{
    AVector<double> v1 = {1, 2, 3, 4, 5}, v2 = {6, 7, 8, 9, 10};
    double d = 5;

    cout << "Check operators" << endl;

    cout << " - " << v1 << " = " << -v1 << endl;

    cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
    cout << v1 << " + " << d << " = " << v1 + d << endl;

    cout << v1 << " - " << v2 << " = " << v1 - v2 << endl;
    cout << v1 << " - " << d << " = " << v1 - d << endl;

    cout << v1 << " * " << v2 << " = " << v1 * v2 << endl;
    cout << v1 << " * " << d << " = " << v1 * d << endl;

    cout << v1 << " / " << v2 << " = " << v1 / v2 << endl;
    cout << v1 << " / " << d << " = " << v1 / d << endl;

    double tmp_d = v1 ^ v2;
    cout << v1 << " ^ " << v2 << " = " << tmp_d << endl;
    AVector<double> v3 = {1, 2, 3}, v4 = {3, 2, 1};
    AVector<double> tmp_v = v3 & v4;
    cout << v3 << " & " << v4 << " = " << tmp_v << endl;


    cout << "++" << v1 << " = " << ++v1 << endl;
    cout << v1 << "++" << " = " << v1++ << "->" << v1 << endl;

    cout << "--" << v1 << " = " << --v1 << endl;
    cout << v1 << "--" << " = " << v1-- << "->" << v1 << endl;

    v1 = {1, 2, 3};
    v2 = {1, 2, 4};
    bool b1 = v1 == v2, b2 = v1 != v2;
    cout << v1 << " == " << v2 << " = " << b1 << endl;
    cout << v1 << " != " << v2 << " = " << b2 << endl;

    v1 = {1, 2, 3};
    v2 = {4, 5, 6};
    b1 = v1 < v2;
    b2 = v1 > v2;
    cout << v1 << " < " << v2 << " = " << b1 << endl;
    cout << v1 << " > " << v2 << " = " << b2 << endl;

    v1 = {1, 2, 3};
    v2 = {1, 3, 3};
    b1 = v1 <= v2;
    b2 = v1 >= v2;
    cout << v1 << " <= " << v2 << " = " << b1 << endl;
    cout << v1 << " >= " << v2 << " = " << b2 << endl;
}

void check_extra_funcs()
{
    cout << "Check extra funcs" << endl;
    AVector<double> v1 = {5, 0}, v2 = {5, 5};

    cout << "angle between" << v1 << " and " << v2 << " = " << v1.angle_between(v2) << endl;

    v2 = {0, 5};
    cout << "is orthogonal" << v1 << " and " << v2 << " = " << v1.is_orthogonal(v2) << endl;
    cout << "is collinear" << v1 << " and " << v2 << " = " << v1.is_collinear(v2) << endl;

    v2 = {-5, 0};
    cout << "is orthogonal" << v1 << " and " << v2 << " = " << v1.is_orthogonal(v2) << endl;
    cout << "is collinear" << v1 << " and " << v2 << " = " << v1.is_collinear(v2) << endl;
}

void check_iteraotors()
{
    cout << "Iterator check" << endl;
    AVector<double> v1 = {1, 2, 3, 4, 5};
    cout << "forward ";
    for (auto it = v1.begin(); it != v1.end() ; ++it)
        cout << *it << " ";
    cout << endl;
    cout << "backward ";
    for (auto it = --v1.end(); it != v1.begin() ; it--)
        cout << *it << " ";
    cout << endl;
    try
    {
        auto it2 = v1.begin();
        for (int i = 0; i < 6; i++) it2++;
        *it2;
    }
    catch (IterIndexError &e)
    {
        cout << e.what() << endl;
    }
}

void check_const_iteraotors()
{
    cout << "Const iterator check" << endl;
    AVector<double> v1 = {1, 2, 3, 4, 5};
    cout << "forward ";
    for (auto it = v1.cbegin(); it != v1.cend() ; ++it)
        cout << *it << " ";
    cout << endl;
    cout << "backward ";
    for (auto it = --v1.cend(); it != v1.cbegin() ; it--)
        cout << *it << " ";
    cout << endl;
    cout << "out of range :";
    try
    {
        auto it2 = v1.cbegin();
        for (int i = 0; i < 6; i++) it2++;
        *it2;
    }
    catch (IterIndexError &e)
    {
        cout << e.what() << endl;
    }
}
