#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::parseArgs(char *args)
{
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

int PmergeMe::checkDuplicates()
{

    std::set<int> s(vec.begin(), vec.end());
    if (s.size() == vec.size())
        return (0);
    return (1);
}

void PmergeMe::vectorPairs(size_t pairSize)
{
    pairSize *= 2;

    if (pairSize > vec.size() / 2) {
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
            swapPairs(pair);
            newPairs.push_back(pair);
        }

        if (takeCount < vec.size())
            leftover.insert(leftover.end(), vec.begin() + takeCount, vec.end());
    } else {

        for (size_t i = 0; i + 2 <= vecpairs.size(); i += 2) {
            std::vector<int> pair;
            pair.insert(pair.end(), vecpairs[i].begin(), vecpairs[i].end());
            pair.insert(pair.end(), vecpairs[i + 1].begin(), vecpairs[i + 1].end());
            swapPairs(pair);
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
    printPairs();
    
}



void PmergeMe::swapPairs(std::vector<int> &pair)
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

void PmergeMe::binarySearch() {

    
    std::vector<int> leftover;

    if (vecSize == 1)
        return;

    vecSize /= 2;
   
    leftover = dividePairs();
    fillMainAndPend();

    printMain(main);
    printPend(pend);
    for (size_t i = 0; i < pend.size(); i++) {

        while (!pend.empty()) {
            size_t indexOfB = getJacobstahlNum(pend.size());
            if (indexOfB == 2)
                continue;

            std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), pend[ indexOfB ], comp);
            main.insert(it, pend[indexOfB]);
            pend.erase(pend.begin() + indexOfB);

            std::cout << "------ Main after insertion in 1rs part------" << std::endl;
            printMain(main);
        }
    }
    if (!pend.empty()) {
        for (size_t i = pend.size(); i > 0; i--) {

                size_t indexOfB = getNonJacobstahlNum(pend.size(), i);
                std::cout << "Not Jacob : " <<  indexOfB << std::endl;
                if (indexOfB == 0)
                    continue;
    
                std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), pend[ indexOfB ], comp);

                main.insert(it, pend[indexOfB]);
                pend.erase(pend.begin() + indexOfB);

                std::cout << "------ Main after insertion in 2nd part ------" << std::endl;
                 printMain(main);
        }
    }
    vecpairs = main;

    if (!leftover.empty())
        vecpairs.push_back(leftover);
    binarySearch();
}


bool comp(const std::vector<int>& a, const std::vector<int>& b) {
        return a.back() < b.back();
}



std::vector<int> PmergeMe::setJacobsthal(size_t arraySize) {
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

size_t PmergeMe::getJacobstahlNum(size_t arraySize) {

    std::vector<int> jacob = setJacobsthal(arraySize);
    for (size_t i = 0; i < jacob.size(); i++) {
        size_t index = jacob[i];
        if (index < arraySize) {
            return(index);
        }
    }
    return(2);
    
}

size_t PmergeMe::getNonJacobstahlNum(size_t arraySize, int idxPend) {
std::cout << arraySize << std::endl;
    // std::vector<int> jacob = setJacobsthal(arraySize);
    // std::vector<int>::iterator it = std::find(jacob.begin(), jacob.end(), idxPend);
    //     if (*it != idxPend)
            return(idxPend);
        // else
        //     return(0);
    
    
}



std::vector<int> PmergeMe::dividePairs() {

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

void PmergeMe::fillMainAndPend() {

    main.clear();
    pend.clear();
    for (size_t i = 0; i < vecpairs.size(); ++i)  {

        if (i == 0) {
            main.push_back(vecpairs[0]);
            continue;
        }
        if(i == 1) {
            main.push_back(vecpairs[1]);
            continue;
        }
        else if (vecpairs[i].size() == vecSize && i % 2 == 0)
            pend.push_back(vecpairs[i]);
        else if (vecpairs[i].size() == vecSize && i % 2 != 0) {
            main.push_back(vecpairs[i]);
        }
    }

}