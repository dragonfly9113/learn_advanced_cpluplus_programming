// Name :	Object.cpp

#include <iostream>
using namespace std;


class Test {
    int id{3};
    string name{"Mike"};

public:
    void print() {
	cout << id << ": " << name << endl;
    }
};


int main() {

    Test test;
    test.print();


    return 0;
}
