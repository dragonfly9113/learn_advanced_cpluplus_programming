// Name :	Decltype.cpp


#include <iostream>
#include <typeinfo>
using namespace std;


int main() {

    string value;

    decltype(value) name = "Bob";

    cout << typeid(name).name() << endl;
    cout << name << endl;

    return 0;
}


