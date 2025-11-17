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

void PmergeMe::vectorPairs(size_t pairSize) {

    printPairs(); 
    pairSize *= 2;

    if (pairSize > vec.size() / 2)
        return;

    std::vector<std::vector<int> > newPairs;
    
    if (vecpairs.empty()) {
        for (size_t i = 0; i + pairSize <= vec.size(); i += pairSize) {
            std::vector<int> pair;
            pair.insert(pair.end(), vec.begin() + i, vec.begin() + i + pairSize);
            swapPairs(pair); 
            newPairs.push_back(pair);
        }
    } else {
        for (size_t i = 0; i + 2 <= vecpairs.size(); i += 2) {
            std::vector<int> pair;
            pair.insert(pair.end(), vecpairs[i].begin(), vecpairs[i].end());
            pair.insert(pair.end(), vecpairs[i+1].begin(), vecpairs[i+1].end());
            swapPairs(pair);
            newPairs.push_back(pair);
        }
    }

    vecpairs = newPairs;

    vectorPairs(pairSize);
}

void PmergeMe::printPairs() {
        std::cout << "Current pairs:\n";
    for (size_t i = 0; i < vecpairs.size(); ++i) {
        std::cout << "(";
        for(size_t j = 0; j < vecpairs[i].size(); ++j) {
            std::cout << vecpairs[i][j];
            if (j < vecpairs[i].size() - 1)
                std::cout << ", ";
        }
        std::cout << ")\n";
    }
    std::cout << "-------\n";
}


void PmergeMe::swapPairs(std::vector<int> &pair) {

     int half = pair.size() / 2;
        for (size_t i = 0; i < pair.size(); i++) {
            if (i + 1 == pair.size()) {
                int &b = pair[i / 2];
                int &a = pair[i];
                if (b > a) {
                    std::swap_ranges(pair.begin(), pair.begin() + half, pair.begin() + half);
                }
            }
    }
}
