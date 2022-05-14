// This file shows how to use const

#include <iostream>
#include "myHeader.h"

using namespace std;

extern const int bufsize_2 = 1024;

void constExample_1()
{
    // 1. must initialize the const
    const int bufsize  = 512;

    // 2. it is legal to use const to initialize a not-const
    int i = 42;
    i = bufsize;
    int j = bufsize;
    cout << "bufsize: " << bufsize <<
        " i: " << i << 
        " j: " << j << endl;

    // 3. By default, const is only available in its own file,
    // to use the const in other file, must add "extern",
    // see PointerRef.cpp.
    cout << "bufsize_2 in const.cpp: " << bufsize_2 << endl;

    // Error 1: cannot change the const value
    // bufsize = 510;

}

void constExample_2()
{
    // 1. reference to const type
    const int ci = 1024;
    const int &r1 = ci; // &r1 is the reference to a const int
    // Error 1: cannot assign value to ci through r1.
    // r1 = 1000;
    // Error 2: ci is constant, r2 is not.
    // int &r2 = ci;

    // 2. pointer to const type
    const double pi = 3.14;
    // Error 3: cannot use normal pointer to point to a const
    // double *ptr = &pi;
    
    //  2.1 use pointer to point to a constant double
    const double *cptr = &pi;
    cout << "pi: " << pi <<
        " ptr: " << *cptr << endl;

    //  2.2 a pointer to const can point to a non-const
    double dval = 3.14;
    cptr = &dval;
    cout << "dval: " << dval <<
        " cptr: " << *cptr << endl;  

    // 指向常量的指针或引用:
    //  不过是它们自以为是罢了, 它们觉得自己指向了常量, 所以自觉的不去改变所指对象的值.
    
    return;
}

void constExample_3()
{
    // 1. 指针是对象而引用不是, 因此指针本身可被定义为常量,
    //  常量指针必须初始化, 不变的是指针本身的值而不是指向的那个值.
    int errNumb = 0;
    int *const curErr = &errNumb;
    cout << "errNumb: " << errNumb <<
        " curErr: " << *curErr << endl;
    *curErr = 1;
    cout << "errNumb New: " << errNumb <<
        " curErr New: " << *curErr << endl;

    const double pi = 3.14;
    // pip是一个常量指针指向常量double
    const double *const pip = &pi;

    // 顶层const: 指针本身是个常量, curErr
    // 底层const: 指针所指的对象是常量, pip即是顶层const也是底层const
}

void constExample_4()
{
    // 常量表达式 constexpr
    // 指值不会改变并且在编译过程就能得到计算结果的表达式
    constexpr int x = 20;
    constexpr int y = x + 1;
    // 只有当size()是一个constexpr函数时, 才是一条正确的声明语句.
    // constexpr int sz = size();

    // constexpr修饰指针, 只对指针有效, 与指针指向的对象无关.
    const int * p = nullptr; // p 是一个指向常量的指针
    constexpr int *q = nullptr; // q 是一个指向整数的常量指针
}