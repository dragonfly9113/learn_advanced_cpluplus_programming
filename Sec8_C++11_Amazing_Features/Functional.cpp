// Name :	Funcitonal.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// comparison function as a function pointer to pass in
bool check(string &test) {

    return test.size() == 3;

}

// use a functor
class Check {
public:
    bool operator()(string &test) {

        return test.size() == 5;

    }
} check1;

// standard function type
void run(function<bool(string&)> check) {
    string test = "stars";
    cout << check(test) << endl;
}


int main() {

    int size = 5;

    vector<string> vec{"one", "two", "three"};

    auto lambda = [size](string test){ return test.size() == size; };

    int count = count_if(vec.begin(), vec.end(), lambda );
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;

    run(lambda);
    run(check1);
    run(check);

    return 0;
}
