// Name :	ring.h
// We define the ring class in this file and just omit the ring.cpp file.


#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring {
public:
    class iterator;
};

template<class T>
class ring<T>::iterator {
public:
    void print();
};

template<class T>
void ring<T>::iterator::print() {
    cout << "Hello from iterator" << T() << endl;
}


#endif    // RING_H_

