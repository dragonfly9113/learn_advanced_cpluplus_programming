// Name :	Using.cpp

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(string test) {

   return test.size() == 4;

}

int main() {
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << match("one") << endl;

    cout << count_if(texts.begin(), texts.end(), match) << endl;

    return 0;
}

