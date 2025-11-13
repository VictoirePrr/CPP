#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& other) {
 (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {

    }
    return *this;
}

PmergeMe::~PmergeMe() {
}



int PmergeMe::parseArgs(char *args) {
    char* endptr;
    errno = 0;

    long num = std::strtol(args, &endptr, 10);
    if (endptr == args) {
        return(1);
    }
    else if (*endptr != '\0') {
        return(1);
    }
    if (num < 0 || num >= INT_MAX || errno == ERANGE) {
        return(1);
    }
        
    vec.push_back(static_cast<int>(num));
    deq.push_back(static_cast<int>(num));
    return(0);
}

int PmergeMe::checkDuplicates() {

      std::set<int> s(vec.begin(), vec.end());
        if (s.size() == vec.size())
            return(0);
    return(1);
}

