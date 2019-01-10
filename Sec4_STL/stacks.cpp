// Name :	stacks.cpp

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;

public:
    Test(string name) : name(name) {

    }

    ~Test() {
	//cout << "Object destroyed" << endl;
    }

    void print() {
	cout << name << endl;
    }
};

int main() {

    // stack is LIFO
    stack<Test> testStack;

    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));
    
    /*
    Test test1 = testStack.top();
    test1.print();

    testStack.pop();
    Test test2 = testStack.top();
    test2.print();
    */

    while (testStack.size() > 0) {
	Test &test = testStack.top();
	test.print();
	testStack.pop();
    }

    // queue is FIFO
    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    while (testQueue.size() > 0) {
	


    }


    return 0;
}

