// Name	:	binary.cpp

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main() {

    Person someone = {"Emily Blunt", 45, 110.5};

    string fileName = "test.bin";

    // write to a binary file //////

    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    if (!outputFile.is_open()) {
	cout << "Could not create file " + fileName << endl;
	return 1;
    }

    outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

    outputFile.close();

    // read from a binary file //////

    Person someoneElse = {};

    ifstream inputFile;

    inputFile.open(fileName, ios::binary);

    if (!inputFile.is_open()) {
	cout << "Could not open input file " + fileName << endl;
	return 1;
    }

    inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

    inputFile.close();

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;

    return 0;
}


