#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other)
    {
    }
    return *this;
}

PmergeMe::~PmergeMe(){
}

void PmergeMe::printProcess(int argc, double elapsed, std::string container) {
    std::cout << "Time to process a range of " << argc << " elements with std::" <<
    container << " : " << BB << elapsed << " seconds."  << RESET << std::endl;
}

void PmergeMe::printBefore(char **argv) {
    std::cout << BR << "Before :" ;
    for (int i = 1; argv[i]; i++) {
        std::cout << " " << argv[i] << " " ;
    }    
    std::cout << RESET << std::endl;
}

void PmergeMe::printAfter(std::string container) {
    std::cout << std::endl;
    std::cout << BG << "After :" ;

    if (container == "vector") {
        for (size_t i = 0; i < vecpairs.size(); ++i)
        {
            for (size_t j = 0; j < vecpairs[i].size(); ++j)
            {
                std::cout << " ";
                std::cout << vecpairs[i][j];
            }
        }
    }

    if (container == "deque") {
        for (size_t i = 0; i < vecpairs.size(); ++i)
        {
            for (size_t j = 0; j < vecpairs[i].size(); ++j)
            {
                std::cout << " ";
                std::cout << vecpairs[i][j];
            }
        }
    }
    std::cout << RESET << std::endl;
}

int PmergeMe::parseArgs(char *args) {
    char *endptr;
    errno = 0;

    long num = std::strtol(args, &endptr, 10);
    if (endptr == args)
        return (1);
    else if (*endptr != '\0')
        return (1);
    if (num < 0 || num >= INT_MAX || errno == ERANGE)
        return (1);

    vec.push_back(static_cast<int>(num));
    deq.push_back(static_cast<int>(num));
    return (0);
}

int PmergeMe::checkDuplicates() {

    std::set<int> s(vec.begin(), vec.end());
    if (s.size() == vec.size())
        return (0);
    return (1);
}

/////////////////////////VECTOR//////////////////////////////////////////////

void PmergeMe::vectorPairs(size_t pairSize)
{
    pairSize *= 2;

    if (pairSize > vec.size()) {
        vecSize = pairSize;
        return;
    }

    std::vector<std::vector<int> > newPairs;
    std::vector<int> leftover;

    if (vecpairs.empty()) {

        size_t fullGroups = vec.size() / pairSize;
        size_t takeCount = fullGroups * pairSize;

        for (size_t i = 0; i + pairSize <= takeCount; i += pairSize) {
            std::vector<int> pair;
            pair.insert(pair.end(), vec.begin() + i, vec.begin() + i + pairSize);
            swapVecPair(pair);
            newPairs.push_back(pair);
        }

        if (takeCount < vec.size())
            leftover.insert(leftover.end(), vec.begin() + takeCount, vec.end());
    } else {

        for (size_t i = 0; i + 2 <= vecpairs.size(); i += 2) {
            std::vector<int> pair;
            pair.insert(pair.end(), vecpairs[i].begin(), vecpairs[i].end());
            pair.insert(pair.end(), vecpairs[i + 1].begin(), vecpairs[i + 1].end());
            swapVecPair(pair);
            newPairs.push_back(pair);
        }

        if (vecpairs.size() % 2 != 0)
            leftover = vecpairs.back();
    }

    vecpairs = newPairs;
    vectorPairs(pairSize);

    if (vecpairs.empty() && !leftover.empty())
        vecpairs.push_back(leftover);
    else if (!vecpairs.empty() && !leftover.empty())
        vecpairs.push_back(leftover);  
}



void PmergeMe::swapVecPair(std::vector<int> &pair)
{

    int half = pair.size() / 2;
    for (size_t i = 0; i < pair.size(); i++) {
        if (i + 1 == pair.size()) {
            int &b = pair[i / 2];
            int &a = pair[i];
            if (b > a)
                std::swap_ranges(pair.begin(), pair.begin() + half, pair.begin() + half);
        }
    }
}

void PmergeMe::vecBinarySearch() {

    
    std::vector<int> leftover;

    if (vecSize == 1)
        return;

    vecSize /= 2;
   
    leftover = divideVecPairs();
    fillVecMainAndPend();

    for (size_t i = 0; i < vpend.size(); i++) {

        while (!vpend.empty()) {
            size_t indexOfB = getVecJacobstahl(vpend.size());
            if (indexOfB == 2)
                continue;

            std::vector<std::vector<int> >::iterator it = std::lower_bound(vmain.begin(), vmain.end(), vpend[ indexOfB ], VecComp);
            vmain.insert(it, vpend[indexOfB]);
            vpend.erase(vpend.begin() + indexOfB);
        }
    }
    vecpairs = vmain;

    if (!leftover.empty())
        vecpairs.push_back(leftover);
    vecBinarySearch();
}


bool VecComp(const std::vector<int>& a, const std::vector<int>& b) {
        return a.back() < b.back();
}



std::vector<int> PmergeMe::setVecJacobsthal(size_t arraySize) {
    std::vector<int> jacob(arraySize);
    jacob[0] = 0;
    if (arraySize > 1) {
        jacob[1] = 1;
        for (size_t i = 2; i < arraySize; ++i) {
            jacob[i] = jacob[i-1] + 2 * jacob[i-2];
        }
    }
    return jacob;
}

size_t PmergeMe::getVecJacobstahl(size_t arraySize) {

    std::vector<int> jacob = setVecJacobsthal(arraySize);
    for (size_t i = 0; i < jacob.size(); i++) {
        size_t index = jacob[i];
        if (index < arraySize) {
            return(index);
        }
    }
    return(2);
}


std::vector<int> PmergeMe::divideVecPairs() {

    std::vector<std::vector<int> > newPairs;
    std::vector<int> leftover;

    for (size_t i = 0; i < vecpairs.size(); ++i) {
        const std::vector<int>& group = vecpairs[i];
        size_t fullGroups = group.size() / vecSize;
        size_t takeCount = fullGroups * vecSize;

        for (size_t j = 0; j + vecSize <= takeCount; j += vecSize) {
            std::vector<int> newPair(group.begin() + j, group.begin() + j + vecSize);
            newPairs.push_back(newPair);
        }
        if (takeCount < group.size()) {
            leftover.insert(leftover.end(), group.begin() + takeCount, group.end());
        }
    }


    vecpairs = newPairs;
    return (leftover);
}

void PmergeMe::fillVecMainAndPend() {

    vmain.clear();
    vpend.clear();
    for (size_t i = 0; i < vecpairs.size(); ++i)  {

        if (i == 0) {
            vmain.push_back(vecpairs[0]);
            continue;
        }
        if(i == 1) {
            vmain.push_back(vecpairs[1]);
            continue;
        }
        else if (vecpairs[i].size() == vecSize && i % 2 == 0)
            vpend.push_back(vecpairs[i]);
        else if (vecpairs[i].size() == vecSize && i % 2 != 0) {
            vmain.push_back(vecpairs[i]);
        }
    }

}

///////////////////////////////////////////////////////////////////////

/////////////////////////DEQUE//////////////////////////////////////////////

void PmergeMe::dequePairs(size_t pairSize)
{
    pairSize *= 2;

    if (pairSize > deq.size()) {
        deqSize = pairSize;
        return;
    }

    std::deque<std::deque<int> > newPairs;
    std::deque<int> leftover;

    if (deqpairs.empty()) {

        size_t fullGroups = deq.size() / pairSize;
        size_t takeCount = fullGroups * pairSize;

        for (size_t i = 0; i + pairSize <= takeCount; i += pairSize) {
            std::deque<int> pair;
            pair.insert(pair.end(), deq.begin() + i, deq.begin() + i + pairSize);
            swapDeqPair(pair);
            newPairs.push_back(pair);
        }

        if (takeCount < deq.size())
            leftover.insert(leftover.end(), deq.begin() + takeCount, deq.end());
    } else {

        for (size_t i = 0; i + 2 <= deqpairs.size(); i += 2) {
            std::deque<int> pair;
            pair.insert(pair.end(), deqpairs[i].begin(), deqpairs[i].end());
            pair.insert(pair.end(), deqpairs[i + 1].begin(), deqpairs[i + 1].end());
            swapDeqPair(pair);
            newPairs.push_back(pair);
        }

        if (deqpairs.size() % 2 != 0)
            leftover = deqpairs.back();
    }

    deqpairs = newPairs;
    dequePairs(pairSize);

    if (deqpairs.empty() && !leftover.empty())
        deqpairs.push_back(leftover);
    else if (!deqpairs.empty() && !leftover.empty())
        deqpairs.push_back(leftover);  
}



void PmergeMe::swapDeqPair(std::deque<int> &pair)
{

    int half = pair.size() / 2;
    for (size_t i = 0; i < pair.size(); i++) {
        if (i + 1 == pair.size()) {
            int &b = pair[i / 2];
            int &a = pair[i];
            if (b > a)
                std::swap_ranges(pair.begin(), pair.begin() + half, pair.begin() + half);
        }
    }
}

void PmergeMe::deqBinarySearch() {

    
    std::deque<int> leftover;

    if (deqSize == 1)
        return;

    deqSize /= 2;
   
    leftover = divideDeqPairs();
    fillDeqMainAndPend();

    for (size_t i = 0; i < dpend.size(); i++) {

        while (!dpend.empty()) {
            size_t indexOfB = getDeqJacobstahl(dpend.size());
            if (indexOfB == 2)
                continue;

            std::deque<std::deque<int> >::iterator it = std::lower_bound(dmain.begin(), dmain.end(), dpend[ indexOfB ], DeqComp);
            dmain.insert(it, dpend[indexOfB]);
            dpend.erase(dpend.begin() + indexOfB);
        }
    }
    deqpairs = dmain;

    if (!leftover.empty())
        deqpairs.push_back(leftover);
    vecBinarySearch();
}


bool DeqComp(const std::deque<int>& a, const std::deque<int>& b) {
        return a.back() < b.back();
}



std::deque<int> PmergeMe::setDeqJacobsthal(size_t arraySize) {
    std::deque<int> jacob(arraySize);
    jacob[0] = 0;
    if (arraySize > 1) {
        jacob[1] = 1;
        for (size_t i = 2; i < arraySize; ++i) {
            jacob[i] = jacob[i-1] + 2 * jacob[i-2];
        }
    }
    return jacob;
}

size_t PmergeMe::getDeqJacobstahl(size_t arraySize) {

    std::deque<int> jacob = setDeqJacobsthal(arraySize);
    for (size_t i = 0; i < jacob.size(); i++) {
        size_t index = jacob[i];
        if (index < arraySize) {
            return(index);
        }
    }
    return(2);
}


std::deque<int> PmergeMe::divideDeqPairs() {

    std::deque<std::deque<int> > newPairs;
    std::deque<int> leftover;

    for (size_t i = 0; i < deqpairs.size(); ++i) {
        const std::deque<int>& group = deqpairs[i];
        size_t fullGroups = group.size() / deqSize;
        size_t takeCount = fullGroups * deqSize;

        for (size_t j = 0; j + deqSize <= takeCount; j += deqSize) {
            std::deque<int> newPair(group.begin() + j, group.begin() + j + deqSize);
            newPairs.push_back(newPair);
        }
        if (takeCount < group.size()) {
            leftover.insert(leftover.end(), group.begin() + takeCount, group.end());
        }
    }

    deqpairs = newPairs;
    return (leftover);
}

void PmergeMe::fillDeqMainAndPend() {

    dmain.clear();
    dpend.clear();
    for (size_t i = 0; i < deqpairs.size(); ++i)  {

        if (i == 0) {
            dmain.push_back(deqpairs[0]);
            continue;
        }
        if(i == 1) {
            dmain.push_back(deqpairs[1]);
            continue;
        }
        else if (deqpairs[i].size() == deqSize && i % 2 == 0)
            dpend.push_back(deqpairs[i]);
        else if (deqpairs[i].size() == deqSize && i % 2 != 0) {
            dmain.push_back(deqpairs[i]);
        }
    }

}