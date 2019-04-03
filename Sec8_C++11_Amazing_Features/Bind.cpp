// Name :	Bind.cpp

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int main() {

    //cout << add(1, 2, 3) << endl;
    
    auto calculate = bind(add, 5, 6, 7);

    cout << calculate() << endl;


    return 0;
}
