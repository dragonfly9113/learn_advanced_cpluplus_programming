// Name :	child.cpp

#include <iostream>

#pragma message("include grandparent.h in child.cpp")

#include "grandparent.h"

#include "parent.h"

using namespace std;


int main() {

    cout << "Hello world!" << endl;

    return 0;
}
