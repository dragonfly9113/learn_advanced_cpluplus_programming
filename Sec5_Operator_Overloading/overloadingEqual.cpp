// Name : 	overloadingEqual.cpp

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;

int main() {

    Complex c1(4, 2);
    Complex c2(3, 2);

    if (c1 != c2) {
	cout << "Not Equal" << endl;
    } else {
	cout << "Equal" << endl;
    }


    return 0;
}

