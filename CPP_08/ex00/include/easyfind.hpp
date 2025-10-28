#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Colors.hpp"

template <typename T>
typename T::const_iterator easyfind(const T &cont, int value);

#include "easyfind.tpp"

#endif
