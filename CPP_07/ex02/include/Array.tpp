#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    _size = 0;
    _array = NULL;
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {

    if (this != &other) {
        delete[] this->_array;
        _size = other._size;
        _array = new T[_size];
    for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _size = n;
    _array = new T[_size];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}