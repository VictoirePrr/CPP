#include "MutantStack.hpp"

#include <list>
#include <string>


static void printTitle(const char* t, const char* color) {
    std::cout << color << "\n=== " << t << " ===" << RESET << std::endl;
}

int main() {
    printTitle("Subject test (MutantStack<int>)", BB);

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    printTitle("Extra checks", BC);

    MutantStack<int>::iterator a = mstack.begin();
    MutantStack<int>::iterator b = mstack.end();
    std::cout << "forward: ";
    for (; a != b; ++a) std::cout << *a << " ";
    std::cout << std::endl;
    MutantStack<int>::reverse_iterator ra = mstack.rbegin();
    MutantStack<int>::reverse_iterator rb = mstack.rend();
    std::cout << "reverse: ";
    for (; ra != rb; ++ra) std::cout << *ra << " ";
    std::cout << std::endl;


    printTitle("Copy / Assign behavior", BM);
    MutantStack<int> copy(mstack);
    MutantStack<int> assign;
    assign = mstack;

    mstack.pop();
    mstack.push(42); 

    std::cout << "original: ";
    for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "copy    : ";
    for (MutantStack<int>::iterator i = copy.begin(); i != copy.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "assign  : ";
    for (MutantStack<int>::iterator i = assign.begin(); i != assign.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;


    printTitle("Const iteration", BY);
    const MutantStack<int> cstack = mstack;
    std::cout << "const forward: ";
    for (MutantStack<int>::const_iterator i = cstack.begin(); i != cstack.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "const reverse: ";
    for (MutantStack<int>::const_reverse_iterator i = cstack.rbegin(); i != cstack.rend(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;


    return 0;
}