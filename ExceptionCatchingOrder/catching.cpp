// Name	: catching.cpp
//

#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
    bool error1 = true;
    bool error2 = true;

    if (error1) {
	throw bad_alloc();
    }

    if (error2) {
	throw exception();
    }
}

int main() {

    try {
	goesWrong();
    }
    catch(bad_alloc &e) {
	cout << "Catching bad_alloc: " << e.what() << endl;
    }
    catch(exception &e) {
	cout << "Catching exception: " << e.what() << endl;
    }

    cout << "Still running..." << endl;

    return 0;
}

