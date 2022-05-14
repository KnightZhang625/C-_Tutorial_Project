// This file shows how to use Pointer

#include <iostream>
#include "myHeader.h"

using namespace std;

void pointerExample_1(){
    // 1. basic definition
    int val = 32;
    int *p = &val;

    cout << "Val: " << val <<
        " P: " << *p << endl;

    // 2. use pointer to change the value
    *p = 33;
    cout << "Val: " << val <<
        " P: " << *p << endl;   

    // 3. initialize null pointer
    int *p2 = nullptr;

    // 4. no need to initialze the Pointer
    int *p1;

    // Error 1: cannot point to the non-object reference
    // int val_1 = 10;
    // int &val_ref = val_1;
    // int *p2 = val_ref;
    // cout << "p2 " << *p2 << endl;

    // Error 2: void* pointer can hold the address of any object
    //  However, we cannot manipulate the void* pointer, since we don't know its type.
    // double obj = 3.14, *pd = &obj;
    // void *ptr = &obj;
    // cout << "PD: " << *pd <<
    //     " PTR: " << *ptr << endl;   

    return;
}

void pointerExample_2(){
    
    // 1. pointer to pointer
    int val = 64, *pi = &val;
    int **ppi = &pi;
    
    cout << "val: " << val <<
        " pi: " << *pi << 
        " ppi: " << **ppi << endl;
    
    
    return;
}