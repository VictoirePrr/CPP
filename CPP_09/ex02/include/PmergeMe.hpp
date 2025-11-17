#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <ctime>

class PmergeMe {

        private :

            std::vector<int> vec;
            std::deque<int> deq;

            std::vector<std::vector<int> > vecpairs;

        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            int parseArgs(char *args);
            int checkDuplicates();
            void vectorPairs(size_t pairSize);
            // void dequePairs();
            void printPairs();
            void swapPairs(std::vector<int> &pair);

};

#endif // PMERGEME_HPP
