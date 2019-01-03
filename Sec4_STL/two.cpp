// Name	: 	two.cpp

#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector< vector<int> > grid(3, vector<int>(4, 7));	// this 2D vector contain 3 vector<int>, each of which contains 4 integers (initialized to 7)

    grid[1].push_back(8);

    for (int row = 0; row < grid.size(); row++) {
	for (int col = 0; col < grid[row].size(); col++) {
	    cout << grid[row][col] << flush;
	}
	cout << endl;
    }


    return 0;
}
