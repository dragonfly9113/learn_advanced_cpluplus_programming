// Name	: parsing.cpp
//
// Parsing text file is not a strength of C++. There are other languages such as Python and Perl which are much better at this kind of job.
// However, sometime we still need to parse some simple text files in our C++ projects.

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string filename = "stats.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open()) {
	return 1;
    }

    while (input) {
	string line;

	getline(input, line, ':');

	int population;
	input >> population;

	//input.get();
	input >> ws;

	if (!input) {
	    break;
	}

	cout << "'" << line << "'" << " -- '" << population << "'" << endl;
    }

    input.close();

    return 0;
}
