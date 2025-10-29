#include "Span.hpp"

Span::Span(unsigned int N) {
    _N = N;
}

Span::Span(const Span& other) {
    this->_N = other._N;
    this->_vector = other._vector;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_N = other._N;
        this->_vector = other._vector;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(unsigned int num) {
    if (_vector.size() < _N)
        _vector.push_back(num);
    else
        throw std::out_of_range("_vector size limit exceeded !");
}

int Span::shortestSpan() {
    if (_vector.size() <= 1)
        throw std::out_of_range("_vector size is too small!");

    std::sort(_vector.begin(), _vector.end());

    int minDiff = INT_MAX;
    for (size_t i = 0; i < _vector.size() - 1; ++i) {
        int diff = _vector[i+1] - _vector[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}


int Span::longestSpan() {
    if (_vector.size() <= 1)
        throw std::out_of_range("_vector size is too small!");

    int minVal = *std::min_element(_vector.begin(), _vector.end());
    int maxVal = *std::max_element(_vector.begin(), _vector.end());

    int maxDiff = maxVal - minVal;
    return maxDiff;
}

void Span::addRange(typename std::vector<int>::iterator begin, typename std::vector<int>::iterator end) {

    std::ptrdiff_t rangeSize = std::distance(begin, end);
    if (_vector.size() >= _N || rangeSize + _vector.size() > _N)
        throw std::out_of_range("_vector size limit exceeded !");
    else
        _vector.insert(_vector.end(), begin, end);

}