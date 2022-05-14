#include <iostream>
#include "myHeader.h"

using namespace std;

extern const int bufsize_2;

int main()
{   
    // 1. Reference Definition Test
    referenceExample_1();

    // 2. Pointer Definition Test
    pointerExample_1();

    // 3. Compound Type Test
    compoundTypeExample_1();

    // 4. advanced Pointer
    pointerExample_2();

    // 5. advanced Reference
    referenceExample_2();

    // 6. const
    constExample_1();

    // 6.1 use const from the const.cpp
    cout << "bufsize_2 in PointerRef.cpp: " << bufsize_2 << endl;

    // 6.2 const example
    constExample_2();
    constExample_3();
    constExample_4();

    // 7. alias
    aliasExamle_1();

    // 8. dealing with types
    dealTypesExample_1();

    return 0;
}