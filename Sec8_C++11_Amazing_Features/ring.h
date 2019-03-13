// Name :	ring.h
// We define the ring class in this file and just omit the ring.cpp file.


#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring {
private:
    int m_size;
    int m_idx;
    T *m_values;

public:
    class iterator;

public:
    ring(int size): m_size(size), m_idx(0), m_values(nullptr) {
	m_values = new T[size];
    }

    ~ring() {
	delete [] m_values;
    }

    int size() {
	return m_size;
    }

    void add(T value) {
	m_values[m_idx] = value;
	m_idx++;
	if (m_idx == m_size) {
	    m_idx = 0;
	}
    }

    T &get(int index) {
	return m_values[index];
    }

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

