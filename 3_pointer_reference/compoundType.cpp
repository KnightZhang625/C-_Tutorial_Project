// This code shows how to use compound type and const.

#include <iostream>
#include "myHeader.h"

using namespace std;

void compoundTypeExample_1()
{   
    // When define the several variables, we can define them in a sequence;
    // [basic type] [declaration 1],  [declaration 2];
    /*
        Example:
            int* p1, p2 -> it's legal, however tend to cause confusion,
                actually, p1 is a int pointer, p2 is a int variable.
    */
    int i = 1024, *p = &i, &r = i;
    cout << "i: " << i <<
        " p: " << *p << " r: " << r << endl;

    return;
}