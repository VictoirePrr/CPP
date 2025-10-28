#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

template <typename Container>
static void testFind(const Container &c, int value, const char *label) 
{
    std::cout << label << " Looking for " << value << "..." << std::endl;
    typename Container::const_iterator it = easyfind(c, value);
    if (it != c.end()) {
        std::cout << BG << "Found value:" << RESET << " " << *it
                  << " (position : " << std::distance(c.begin(), it) << ")"
                  << std::endl;
    } 
    else
        std::cout << BR << "Not found." << RESET << std::endl;
}

int main(void) {
    std::cout << "\n" << BB << "=== Test with std::vector ===" << RESET << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i * 10);
    testFind(v, 30, "[vector]");
    testFind(v, 42, "[vector]");

    std::cout << "\n" << BB << "=== Test with std::list ===" << RESET << std::endl;
    std::list<int> l;
    for (int i = 5; i < 10; i++)
        l.push_back(i);
    testFind(l, 8,  "[list]");
    testFind(l, 4,  "[list]");

    std::cout << "\n" << BB << "=== Test with std::deque ===" << RESET << std::endl;
    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);
    testFind(d, 200, "[deque]");
    testFind(d, 123, "[deque]");

    std::cout << "\n" << BB << "=== Edge case: empty container ===" << RESET << std::endl;
    std::vector<int> empty;
    testFind(empty, 1, "[empty vector]");
    
    return 0;
}
