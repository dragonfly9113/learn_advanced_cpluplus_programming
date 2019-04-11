// Name: 	main.cpp

#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

    Bitmap bitmap(800, 600);

    if (bitmap.write("test.bmp")) {
	cout << "Bitmap writing OK" << endl;
    }

    cout << "Finished." << endl;
    return 0;
}

