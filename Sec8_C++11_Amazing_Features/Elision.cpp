// Name :	Elision.cpp

#include <iostream>
#include <vector>
#include <memory.h>   // for memset() and memcpy(), it seems it is also OK if #include <cstring>
using namespace std;


class Test {
private:
    static const int SIZE = 100;
    int *_pBuffer;

public:
    Test() {
	cout << "constructor" << endl;
	_pBuffer = new int[SIZE]{0};

	// the old way to reset the memory:
	//memset(_pBuffer, 0, SIZE * sizeof(int));
    }

    Test(int x) {
	cout << "parameterized constructor" << endl;
	_pBuffer = new int[SIZE]{};

	for (int i = 0; i < SIZE; i++) {
	    _pBuffer[i] = 7 * x;
	}
    }

    Test(const Test &other) {
	cout << "copy constructor" << endl;
	_pBuffer = new int[SIZE]{};

	// Intuitive way but may not be most efficient:
	//for (int i = 0; i < SIZE; i++) {
	//    _pBuffer[i] = other._pBuffer[i];
	//}

	memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    }

    Test &operator=(const Test &other) {
	cout << "assignment" << endl;
	
	memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));

	return *this;
    }

    ~Test() {
	cout << "destructor" << endl;
	delete[] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
}

void check(const Test &value) {
    cout << "lvalue function" << endl;
}

void check(Test &&value) {
    cout << "rvalue function" << endl;
}

int main() {

    Test test1 = getTest();

    //cout << test1 << endl;

    //vector<Test> vec;
    //vec.push_back(Test());

    //Test &rTest1 = test1;  // OK: test1 is Lvalue, thus rTest1 is a Lvalue reference

    //Test &rTest2 = getTest(); // Error: the return value of getTest() is a Rvalue (temp value), we cannot bind a reference to a Rvalue.
    //const Test &rTest2 = getTest();  // OK: const reference can be bound to any value (lvalue or rvalue), it basically extends the lifetime of the tempoary return value of getTest().

    //Test test2(Test(1)); // OK: Test(1) returns a temp Test obj (rvalue) and it is passed to Test copy constructor which takes a const Test reference. This is an example to show why we should define the parameter in copy constructor a const ref.

    //Test &&rTest2 = test1;  // Error
    Test &&rTest2 = Test();
    Test &&rTest3 = getTest();

    check(test1);
    check(getTest());
    check(Test());


    return 0;
}


