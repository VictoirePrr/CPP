#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

template <class T>
class Array {

    private:

        unsigned int _size;
        T *_array;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        unsigned int size() const;
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
