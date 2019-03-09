// Name : Object.cpp

#include <iostream>
using namespace std;

class Parent {
private:
    int one;

public:
    Parent(): one(0) {

    }

    Parent(const Parent &other): one(0) {

        one = other.one;
	cout << "copy parent" << endl;

    }

    virtual void print() {
	cout << "parent: one = " << one << endl;
    }

    virtual ~Parent() {

    }
};

class Child : public Parent {
private:
    int two;

public:
    Child(): two(1) {

    }

    void print() {
        cout << "child: two = " << two << endl;
    }
};


int main() {

    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();

    return 0;
}


