// Name	: writing.cpp
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    //ofstream outFile;
    fstream outFile;

    string outputFileName = "text.txt";

    outFile.open(outputFileName, ios::out);

    if(outFile.is_open()) {
	outFile << "Hello there, Buenos Diaz" << endl;
	outFile << 123 << endl;
	outFile.close();
    }
    else {
	cout << "Could not create file: " << outputFileName << endl;
    }

    return 0;
}

