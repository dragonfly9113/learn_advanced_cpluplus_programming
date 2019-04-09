// name :	Bitmap.h

#pragma once

namespace caveofprgramming {

class Bitmap {
private:
    int m_width{0};
    int m_height{0};

public:
    Bitmap(int width, int height);
    bool write(string filename);
    virtual ~Bitmap();
};


} // namespace caveofprogramming

