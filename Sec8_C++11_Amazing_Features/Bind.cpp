// Name :	Bind.cpp

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

// standard function
int run(function<int(int, int, int)> func) {
    return func(10, 20, 30);
}

int main() {

    auto calculate = bind(add, _1, _2 ,_3);  // _1, _2, _3 are placeholders

    //cout << calculate(10, 20, 30) << endl;
    
    cout << run(calculate) << endl;


    return 0;
}
