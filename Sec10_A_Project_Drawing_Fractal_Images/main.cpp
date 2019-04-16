// Name: 	main.cpp

#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
	for (int x = 0; x < WIDTH; x++)
	{
	    bitmap.setPixel(x, y, 255, 0, 0);
	}
    }

    if (bitmap.write("test.bmp")) {
	cout << "Bitmap writing OK" << endl;
    }

    cout << "Finished." << endl;
    return 0;
}

