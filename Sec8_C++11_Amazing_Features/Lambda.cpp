// Name :	Lambda.cpp

#include <iostream>
using namespace std;

void testGreet(void (*pFunc)(string name) ) {

    pFunc("Mike");

}


int main() {

    auto pGreet = [](string name){ cout << "Hello " << name << endl; };

    pGreet("William");

    testGreet(pGreet);

    auto pDivide = [](double a, double b) -> double {

	if (b == 0.0) {
	    return 0;
	}

        return a / b;
    };

    cout << pDivide(10.0, 5.0) << endl;
    cout << pDivide(10.0, 0.0) << endl;


    return 0;
}

