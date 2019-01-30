// Name :	Function.cpp

#include <iostream>
using namespace std;

void test(int value) {
    cout << "Hello: " << value << endl;
}

int main() {
    test(7);

    // declare a function pointer which points to a function that takes no parameter and returns void:
    //void (*pTest)();

    // assign a function address to the function pointer:
    //pTest = &test;
    //pTest = test;

    // usually we can do declaration and assignment at the same time:
    void (*pTest)(int) = test;

    // call the function via the function pointer:
    //(*pTest)();
    pTest(8);


    return 0;
}


