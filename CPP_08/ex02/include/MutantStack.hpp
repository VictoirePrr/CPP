#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include "Colors.hpp"

template <class T>
class MutantStack {

        private :


        public :

            MutantStack();
            MutantStack(const MutantStack& other);
            MutantStack& operator=(const MutantStack& other);
            ~MutantStack();

            void push(unsigned int n);
            template <typename T>
            const T& top() const;
            std::size_t size() const;
            typename T::iterator begin();
            typename T::iterator end();


};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
