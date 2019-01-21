// Name :	Template2.cpp
// Template functions and type inference

#include <iostream>
using namespace std;

template<class T>
void print(T n) {
    cout << "Template version: " << n << endl;
}

void print(int n) {
    cout << "Non-template version: " << n << endl;
}

template<class T>
void show() {
    cout << T() << endl;
}


int main() {

    print<string>("Hello");
    print<int>(5);

    print("Hi, there");

    print<>(6);

    show<string>();

    return 0;
}

