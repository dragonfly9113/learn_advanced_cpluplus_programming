// Name :	nested_demo.cpp

#include <iostream>
using namespace std;

/*
class enclose {
    struct nested {
        void g() {
	    cout << "enclose::nested::g() is called" << endl;
	}
    };

public:
    static nested f() { return nested(); }
};
*/

int x, y;    // globals

class enclose {
    int x;    // private members
    static int s;

public:
    struct inner {   // nested class
        void f(int i) {
	    //x = i;   // Error: can't write to non-static enclose::x without instance

	    int a = sizeof x;
	    //s = i;    // OK: can assign to the static enclose::s
	    ::x = i;  // OK: can assign to global x
	    y = i;    // OK: can assign to global y

	    cout << "enclose::inner::f() is called. a = " << a << endl;
	}

	void g(enclose *p, int i) {
	    p->x = i;   // OK: assign to enclose::x
	    cout << "enclose::inner::g() is called." << endl;
	}

    }; 

};


int main() {

    //enclose::nested n1 = enclose::f();  // error: 'nested' is private
    //enclose::f().g();
    //auto n2 = enclose::f();
    //n2.g();

    auto n1 = enclose::inner();
    enclose e1 = enclose();

    n1.f(100);
    n1.g(&e1, 200);

    return 0;
}

