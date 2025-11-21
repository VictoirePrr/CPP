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

#include "Colors.hpp"

class PmergeMe {

        private :

            std::vector<int> vec;
            size_t vecSize;

            std::vector<std::vector<int> > vecpairs;
            std::vector<std::vector<int> > vmain;
            std::vector<std::vector<int> > vpend;

            std::deque<int> deq;
            size_t deqSize;

            std::deque<std::deque<int> > deqpairs;
            std::deque<std::deque<int> > dmain;
            std::deque<std::deque<int> > dpend;


        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            void printBefore(char **argv);
            void printAfter(std::string container);
            void printProcess(int argc, double elapsed, std::string container);

            int parseArgs(char *args);
            int checkDuplicates();

 /////////////////////////VECTOR//////////////////////////////////////////////

            void vectorPairs(size_t pairSize);
            void swapVecPair(std::vector<int> &pair);

            void vecBinarySearch();
            std::vector<int> divideVecPairs();
            void fillVecMainAndPend();
            std::vector<int> setVecJacobsthal(size_t arraySize);
            size_t getVecJacobstahl(size_t arraySize);


/////////////////////////DEQUE//////////////////////////////////////////////
            
            void dequePairs(size_t pairSize);
            void swapDeqPair(std::deque<int> &pair);

            void deqBinarySearch();
            std::deque<int> divideDeqPairs();
            void fillDeqMainAndPend();
            std::deque<int> setDeqJacobsthal(size_t arraySize);
            size_t getDeqJacobstahl(size_t arraySize);

};

bool VecComp(const std::vector<int>& a, const std::vector<int>& b);
bool DeqComp(const std::deque<int>& a, const std::deque<int>& b);

#endif // PMERGEME_HPP
