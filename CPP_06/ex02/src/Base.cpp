#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {
}


Base::~Base() {
}

void Base::printClass(void) {
    std::cout << "Base" << std::endl;
}

Base * generate(void) {

    int randomValue = std::rand() % 3;
    if (randomValue == 1)
        return(new A);
    else if (randomValue == 2)
        return(new B);
    else if (randomValue == 3)
        return(new C);
    return(new C);
}

void identify(Base* p) {

    A* Aptr = dynamic_cast<A*>(p);
    if (Aptr) 
        Aptr->printClass();
    B* Bptr = dynamic_cast<B*>(p);
    if (Bptr) 
        Bptr->printClass();
    C* Cptr = dynamic_cast<C*>(p);
    if (Cptr) 
        Cptr->printClass();

}

void identify(Base& p) {

    try {
     A& Aptr = dynamic_cast<A&>(p);
     Aptr.printClass();
     return ;
    } catch (const std::exception& e) {}

    try {
     B& Bptr = dynamic_cast<B&>(p);
     Bptr.printClass();
     return ;
    } catch (const std::exception& e) {}

    try {
     C& Cptr = dynamic_cast<C&>(p);
     Cptr.printClass();
     return ;
    } catch (const std::exception& e) {}
}