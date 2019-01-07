// Name : 	custom.cpp

// lecture 17: custom objects as map values
// lecture 18: custom objects as map keys

#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;

public:

    // a default constructor is necessary because it is needed when constructing map entries
    Person() : name(""), age(0) {
    }

    // a copy constructor
    Person(const Person &other) {
	name = other.name;
	age = other.age;
    }

    Person(string name, int age) : 
	    name(name), age(age) {
    }

    void print() const {
	cout << name << ": " << age << flush;
    }

    bool operator<(const Person &other) const {

	if (name == other.name) {
	    return age < other.age;
	} else {
            return name < other.name;
	}
    }

};


int main() {

    /* use custom objects as map values
    map<int, Person> people;    // use custom object as map value

    people[50] = Person("Mike", 40);
    people[32] = Person("Vicky", 30);
    people[1] = Person("Raj", 20);
   
    people.insert(make_pair(55, Person("Bob", 45)));
    people.insert(make_pair(55, Person("Sue", 24)));

    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
	cout << it->first << ": " << flush;
	it->second.print();
    }
    */

    /* use custom objects as map keys */
    map<Person, int> people;

    people[Person("Mike", 40)] = 40;
    people[Person("Mike", 444)] = 123;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
	cout << it->second << ": " << flush;
	it->first.print();
	cout << endl;
    }


    return 0;
}


