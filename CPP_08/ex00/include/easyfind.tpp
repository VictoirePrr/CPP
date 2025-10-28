#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::const_iterator easyfind(const T &cont, int value) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), value);
    if (it == cont.end())
        return cont.end();
    else
        return it;
}
