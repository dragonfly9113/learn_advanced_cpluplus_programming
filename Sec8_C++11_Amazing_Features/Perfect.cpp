// Name :	Perfect.cpp


#include <iostream>
using namespace std;


class Test {

};

template<typename T>
void call(T &&arg) {
    check(forward<T>(arg));
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}

int main() {

    Test test;

    call(test);

    return 0;
}
