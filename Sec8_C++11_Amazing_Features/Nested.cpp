// Name :	Nested.cpp


#include <iostream>
#include "ring.h"
using namespace std;


int main() {

    ring<string>::iterator it;

    it.print();

    ring<string> r = ring<string>(3);

    return 0;
}
