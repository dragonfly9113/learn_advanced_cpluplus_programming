// Name : 	sets.cpp

#include <iostream>
#include <set>
using namespace std;

class Person {

private:
    string name;
    int age;

public:
    Person() : 
	name(""), age(0) {}
    
    Person(string name, int age) : 
	name(name), age(age) {}

    Person(const Person &other) {
        name = other.name;
	age = other.age; 
    }

    void print() const {
	cout << name << ": " << age << flush;
    }

    bool operator<(const Person &other) const{
	return name < other.name;
    }


};


int main() {

    set<int> numbers;

    numbers.insert(50);
    numbers.insert(40);
    numbers.insert(10);
    numbers.insert(30);

    for (auto it = numbers.begin(); it != numbers.end(); it++) {
	cout << *it << endl;
    }

    // try to define a set of custom objects
    set<Person> people;

    people.insert(Person("Mike", 50));
    people.insert(Person("Raj", 10));
    people.insert(Person("Vicky", 30));
    people.insert(Person("Bob", 20));

    for (auto it = people.begin(); it != people.end(); it++) {
	it->print();
	cout << endl;
    }



    return 0;
}


