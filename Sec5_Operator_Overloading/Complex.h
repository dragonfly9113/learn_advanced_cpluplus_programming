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

    // overloading operator== with a Complex member method
    bool operator==(const Complex &other) const;
    bool operator!=(const Complex &other) const;

    Complex operator*() const;
};

ostream &operator<<(ostream &out, const Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);

Complex operator+(const Complex &c1, const double d);

Complex operator+(const double d, const Complex &c1);

// overloading operator== with a stand-alone function
//bool operator==(const Complex &c1, const Complex &c2);

} // namesapce caveofprogramming

#endif // COMPLEX_H_
