// Name: 	main.cpp

#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"

using namespace std;

int main() {

    cout << "Hello World!" << endl;

    cout << sizeof(struct BitmapFileHeader) << endl;

    cout << sizeof(struct BitmapInfoHeader) << endl;

    return 0;
}

