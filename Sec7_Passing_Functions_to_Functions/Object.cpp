// Name : Object.cpp

#include <iostream>
using namespace std;

class Parent {

public:
    void print() {
	cout << "parent" << endl;
    }

};


class Child : public Parent {

public:
	void print() {
	cout << "child" << endl;

    }
    
};


int main() {

    Child c1;



}


