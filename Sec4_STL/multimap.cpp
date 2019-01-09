// Name :	multimap.cpp

#include <iostream>
#include <map>
using namespace std;

int main() {

    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vicky"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(20, "Bob"));

    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
	cout << it->first << ": " << it->second << endl;
    }

    // you can use find() to search for a certain key
    cout << endl;

    for (multimap<int, string>::iterator it = lookup.find(10); it != lookup.end(); it++) {
	cout << it->first << ": " << it->second << endl;
    }

    // you can use equal_range() to find a certain range
    cout << endl;

    // define a pair of iterators to store the beginninng and ending of a range
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for (multimap<int, string>::iterator it = its.first; it != its.second; it++) {
	cout << it->first << ": " << it->second << endl;
    }


    // use C++ 11's new feature "auto" to greatly simplify the above code:
    cout << endl;

    // define a pair of iterators to store the beginninng and ending of a range
    auto its1 = lookup.equal_range(30);

    for (auto it = its1.first; it != its1.second; it++) {
	cout << it->first << ": " << it->second << endl;
    }



    return 0;
}

