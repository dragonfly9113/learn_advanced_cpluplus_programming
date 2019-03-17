// Name :	Lambda.cpp

#include <iostream>
using namespace std;

void testGreet(void (*pFunc)(string name) ) {

    pFunc("Mike");

}

void runDivide( double (*divide)(double, double) ) {

    cout << divide(9, 3) << endl;

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

    runDivide(pDivide);
    cout << endl;

    int one = 1;
    int two = 2;
    int three = 3;

    // capture one and two by value
    [one, two](){ cout << one << ", " << two << endl; }();

    // capture all local variables by value
    [=](){ cout << one << ", " << two << ", " << three << endl; }();

    // default capture all local variables by value, but capture three by reference
    [=, &three](){ three = 7; cout << one << ", " << two << ", " << three << endl; }();

    cout << one << ", " << two << ", " << three << endl;

    return 0;
}

