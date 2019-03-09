// Name		: Functors.cpp

#include <iostream>
using namespace std;

struct MatchTest {
    bool operator()(string &text) {
	return text == "lion";
    }
};

void check(string text) {


}


int main() {

    MatchTest pred;

    string value = "lion1";

    cout << pred(value) << endl;


    return 0;
}

