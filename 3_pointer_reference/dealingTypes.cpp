// This code shows how to use alias, auto, decltype

#include <iostream>
#include <string>
#include "myHeader.h"

using namespace std;

void dealTypesExample_1()
{
    // alias
    using intp = int*;
    int i = 10;
    // p 并不是指向const int的指针,
    // 别名int*被看作一个整体, 所以p是一个常量指针指向int
    const intp p = &i;
    *p = 12;
    cout << "i: " << i << endl;

    // Error 1: 所以不能改变p本身的值
    // int j =  100;
    // p = &j;

    // auto
    auto i_2 = 0, *p2 = &i_2;
    cout << "i_2: " << i_2 <<
        " p2: " << *p2 << endl;
    
    // auto + 引用: 使用的是引用的数据类型
    int i2 = 0, &r = i2;
    auto a = r; // a是int, r是引用,直接用它引用的对象类型 int.

    // auto 一般忽略顶层const, 但保留底层const
    const int ci = 3, &cr = ci;
    auto b = ci; // b是int
    auto c = cr; // c是int
    auto d = &i2; // d是一个整形指针
    auto e = &ci; // ci是常量, 但是&ci不是, 所以是底层const, e为指向整形常量的指针

    // 若希望推断出的auto类型是一个顶层const
    const auto f = ci; // ci是int(顶层const忽略), 但是声明加了const

    // 可将引用类型设为auto, 此时原来的初始化规则仍适用
    auto &g = ci; // g是整形常量引用
    // auto &h = 42; // 不能为非常量绑定字面值
    const auto &j = 42;

    // decltype 类型指示符
    // 希望从表达式的类型推断出要定义的变量的类型, 但是不想用该表达式的值

    // decltype处理顶层const和引用的方式与auto有些许不同.
    // 若decltype使用的表达式是一个变量, 则decltype返回该变量的类型(包括顶层const和引用在内)
    decltype(ci) x = 0; // x是const int
    auto b2 = ci; // b是int

    decltype(cr) y = x; // y是const int&
    auto c2 = cr; // c是int

    // cj是引用, 必须赋值
    // decltype(cj) z;

    int i3 = 42, *p3 = &i3, &r2 = i3;
    decltype(r2 + 0) in_b; // r是int, r+0是int, b是为初始化的int
    // decltype(*p3) c3; // *p是int&, 必须初始化

    // decltype的表达式如果加上了括号, 结果是引用
    // decltype((i3)) d; // 错误, 加了括号, d为int&, 必须初始化
    decltype(i3) un_e; // e是一个(为初始化的)int

}