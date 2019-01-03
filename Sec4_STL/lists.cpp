// Name : 	lists.cpp
#include <iostream>
#include <list>

using namespace std;


int main() {

    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    // insert a new element before a certain node
    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    cout << "Element: " << *it << endl;

    // delete an element
    it = numbers.begin();
    it++;
    it = numbers.erase(it);
    cout << "Element: " << *it << endl;

    /*
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ) {
	if (*it == 2) {
	    numbers.insert(it, 1234);
	}

	if (*it == 1) {
	    it = numbers.erase(it);
	} else {
	    it++;
	}
    }
    */

    // it is better to use a while loop than for loop to do something like above
    it = numbers.begin();
    while (it != numbers.end()) {
	if (*it == 2) {
	    numbers.insert(it, 1234);
	}

	if (*it == 1) {
	    it = numbers.erase(it);
	} else {
	    it++;
	}
    }


    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }


    return 0;
}

