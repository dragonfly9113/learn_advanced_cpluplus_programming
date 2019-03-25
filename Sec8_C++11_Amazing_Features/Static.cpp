// Name :	Static.cpp


#include <iostream>
using namespace std;


class Parent {
public:
    void speak() {
	cout << "Parent speak!" << endl;
    }

};

class Brother: public Parent {


};


class Sister: public Parent {



};

int main() {

    Parent parent;
    Brother brother;

    Parent *ppb = &brother;

    Parent &&p = static_cast<Parent &&>(parent);

    p.speak();

    return 0;
}



