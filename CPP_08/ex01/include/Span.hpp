#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {

    private:

        unsigned int _N;
        std::vector<int> _vector;
        Span();

    public:

        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(unsigned int num);
        void addRange();
        int shortestSpan();
        int longestSpan();
};

#endif
