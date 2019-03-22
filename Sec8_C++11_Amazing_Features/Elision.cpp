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

int main() {

    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    int value1 = 7;

    Test *pTest1 = &test1;
    //Test *pTest2 = &getTest();  // Error: return of getTest() is temporary value (Rvalue)

    return 0;
}


