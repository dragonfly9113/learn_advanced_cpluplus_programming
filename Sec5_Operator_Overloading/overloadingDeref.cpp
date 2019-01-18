// Name : 	overloadingDeref.cpp
// Complex conjugate:
// c1 = (2, 4)
// *c1 = (2, -4)
//
// But the conjugate sign * is the same as deference sign. Therefore we need to overload it.

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;

int main() {

    Complex c1(2, 4);

    cout << *c1 + Complex(4, 3) << endl;


    return 0;
}

