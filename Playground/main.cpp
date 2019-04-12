// name :	main.cpp

#include <iostream>
using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues(int i) {
    double v[] = {11.0, 22.0, 33.0, 44.0, 55.0};

    return v[i];
    //return vals[i];
}

int main() {

    for (int i = 0; i < 5; i++) {
	cout << vals[i] << " ";
    }
    cout << endl;

    setValues(1) = 20.23;
    setValues(3) = 70.8;

    for (int i = 0; i < 5; i++) {
	cout << vals[i] << " ";
    }
    cout << endl;


    return 0;
}

