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
    int m_pos;
    T *m_values;

public:
    class iterator;

public:
    ring(int size): m_size(size), m_pos(0), m_values(nullptr) {
	m_values = new T[size];
    }

    ~ring() {
	delete [] m_values;
    }

    int size() {
	return m_size;
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T value) {
	m_values[m_pos] = value;
	m_pos++;
	if (m_pos == m_size) {
	    m_pos = 0;
	}
    }

    T &get(int pos) {
	return m_values[pos];
    }

};

template<class T>
class ring<T>::iterator {
private:
    int m_pos;
    ring &m_ring;

public:
    iterator(int pos, ring &aRing): m_pos(pos), m_ring(aRing) {

    }

    iterator &operator++(int) {
        m_pos++;

	return *this;
    }

    iterator &operator++() {
        m_pos++;

	return *this;
    }


};



#endif    // RING_H_
