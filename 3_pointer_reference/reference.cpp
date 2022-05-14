// This file shows the use of reference.

#include <iostream>
#include "myHeader.h"

using namespace std;

void referenceExample_1(){
    // 1. definition
    int val = 1024;
    int &ref = val;

    cout << "Val: " << val <<
        " Ref: " << ref << endl;
    
    // 2. change the val by ref
    ref = 1025;
    cout << "Val: " << val <<
        " Ref: " << ref << endl;

    // Error 1: the type of ref must be the same as the object
    // double pi = 3.1416926;
    // int &ref_2 = pi;

    // Error 2: the ref can only to a object, not a literal or expression
    // int &ref_3 = 3;

    // Error 3: ref must be initialized
    // int &ref_4;

    return;
}

void referenceExample_2()
{
    // 1. reference to pointer
    int i = 42, *p = &i;
    int *&ref = p;

    cout << "i: " << i <<
        " p: " << *p << 
        " ref: " << *ref << endl;
}