// This code shows how to use type alias

#include <iostream>
#include "myHeader.h"

using namespace std;

void aliasExamle_1()
{
    using pName = int*;
    int i = 1024;
    const pName pi = &i;

    *pi = 1025;
    cout << "i: " << i << endl;

    // Error 1: take pName=int* as a whole,
    //  so that const pName is a const pointer point to a int.
    // As the result, cannot change value of pointer pi
    // int j = 10;
    // pi = &j;

    return;
}