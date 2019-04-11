// Name :	Playground.cpp

#include <iostream>
using namespace std;


int main() {

    int value1 = 5;
    int value2 = 6;

    const int* const ptr = &value1;
    *ptr = value2;

    cout << *ptr << endl;



    return 0;
}
