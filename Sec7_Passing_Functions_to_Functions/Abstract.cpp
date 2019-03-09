// Name :	Abstract.cpp


#include <iostream>
using namespace std;


class Animal {
public:
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog: public Animal {
public:
    virtual void speak() {
	cout << "Woof!" << endl;
    }
};

class Labrador: public Dog {
public:
    virtual void run() {
	cout << "Labrador running" << endl;
    }
};

int main() {

    //Dog d1 = Dog();
    //d1.speak();
    
    Labrador lab;
    lab.run();
    lab.speak();

    Animal &animal = lab;
    animal.run();
    animal.speak();

    Animal *animals[5];
    animals[0] = &lab;
    animals[0]->run();
    animals[0]->speak();


    return 0;
}


