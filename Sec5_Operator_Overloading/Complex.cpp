// Name : 	Complex.cpp

#include "Complex.h"

namespace caveofprogramming {

ostream &operator<<(ostream &out, const Complex &c) {
   out << "(" << c.getReal() << ", " << c.getImaginary() << ")" << flush;
   return out;
}

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
    return *this;
}


} // namespace caveofprogramming



