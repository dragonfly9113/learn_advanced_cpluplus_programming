// Name :	BitmapFileHeader.h

#pragma once

#include <cstdint>

using namespace std;

#pragma pack(2)   // pack the structure based on 2 bytes

struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

