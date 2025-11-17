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
            std::vector<std::vector<int> > sisterIdx;

        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            int parseArgs(char *args);
            int checkDuplicates();
            void vectorPairs(size_t pairSize);
            void swapPairs(std::vector<int> &pair);
            void binarySearch(size_t pairSize);
            void printPairs() {
                    std::cout << "Current pairs:\n";
                    for (size_t i = 0; i < vecpairs.size(); ++i)
                    {
                        std::cout << "(";
                        for (size_t j = 0; j < vecpairs[i].size(); ++j)
                        {
                            std::cout << vecpairs[i][j];
                            if (j < vecpairs[i].size() - 1)
                                std::cout << ", ";
                        }
                        std::cout << ")\n";
                    }
                    std::cout << "-------\n";
                }
                // void dequePairs();
};

#endif // PMERGEME_HPP
