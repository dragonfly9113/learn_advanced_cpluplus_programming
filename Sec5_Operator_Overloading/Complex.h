// Name : 	Complex.h

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace caveofprogramming {

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real, double imaginary);
    // copy constructor
    Complex(const Complex &other);
    // assignment operator overloading
    const Complex &operator=(const Complex &other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

};

ostream &operator<<(ostream &out, const Complex &c);


} // namesapce caveofprogramming

#endif // COMPLEX_H_
