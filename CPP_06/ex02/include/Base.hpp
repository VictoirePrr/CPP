#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base {

        public :

            Base();
            virtual ~Base();

            virtual void printClass(void);

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // BASE_HPP
