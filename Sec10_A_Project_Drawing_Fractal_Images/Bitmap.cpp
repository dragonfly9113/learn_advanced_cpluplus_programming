// name :	Bitmap.cpp

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <string>
#include <iostream>

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming {

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    
    uint8_t *pPixel = m_pPixels.get();

    pPixel += (y * 3) * m_width + (x * 3);

    pPixel[0] = blue;  // bitmap is little-endian foramt: least significant value (Blur) is stored first.
    pPixel[1] = green;
    pPixel[2] = red;
}

bool Bitmap::write(string filename) {
    
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    // fileSize: total size of the bitmap file.
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    cout << fileHeader.fileSize << endl;
    
    // dataOffset: distance from the start of file to where data starts.
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    cout << fileHeader.dataOffset << endl;

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(filename, ios::out | ios::binary);
    if(!file) {
	return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width * m_height * 3);

    file.close();
    if(!file) {
	return false;
    }

    return true;
}


Bitmap::~Bitmap() {

}


} // namespace caveofprogramming


