// Name :	Enhanced.cpp


#include <iostream>
#include <vector>
using namespace std;

int main() {

    auto texts = {"one", "two", "three"};

    for (auto text : texts) {
	cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(11);

    for (auto number : numbers) {
	cout << number << endl;
    }


    return 0;
}

