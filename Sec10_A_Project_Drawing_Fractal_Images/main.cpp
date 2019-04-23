// Name: 	main.cpp

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;
using namespace caveofprogramming;

int main() {

    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    //double min = 999999;
    //double max = -999999;
    
    ZoomList zoomList(WIDTH, HEIGHT);

    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 1));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> pixelIterations(new int[HEIGHT * WIDTH]{});

    for (int y = 0; y < HEIGHT; y++)
    {
	for (int x = 0; x < WIDTH; x++)
	{
	    pair<double, double> coords = zoomList.doZoom(x, y);

	    int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            int idx = y * WIDTH + x;
            pixelIterations[idx] = iterations;

	    if (iterations != Mandelbrot::MAX_ITERATIONS) {
	        histogram[iterations]++;
            }
	}
    }

    // Calculate the total number of iterations
    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
	total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++)
    {
	for (int x = 0; x < WIDTH; x++)
	{
	    uint8_t red = 0;
	    uint8_t green = 0;
	    uint8_t blue = 0;

	    int iterations = pixelIterations[y * WIDTH + x];

	    if (iterations != Mandelbrot::MAX_ITERATIONS) {
	        double hue = 0.0;

	        for (int i = 0; i <= iterations; i++) {
	  	    hue += ((double)histogram[i]) / total;
	        }

	        green = pow(255, hue);
            }

	    bitmap.setPixel(x, y, red, green, blue);
        }
    }

    if (bitmap.write("test.bmp")) {
	cout << "Bitmap writing OK" << endl;
    }

    cout << "Finished." << endl;
    return 0;
}

