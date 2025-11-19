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
            size_t vecSize;
            std::deque<int> deq;

            std::vector<std::vector<int> > vecpairs;
            std::vector<int> sisterIdx;


        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            int parseArgs(char *args);
            int checkDuplicates();
            void vectorPairs(size_t pairSize);
            void swapPairs(std::vector<int> &pair);
            std::vector<int> dividePairs();
            void setSisterIdx(std::vector<std::vector<int> > main);
            size_t getSisterIdx(size_t indexOfB);
            std::vector<int> setJacobsthal(size_t arraySize);
            size_t getJacobstahlNum(size_t arraySize);
            size_t getNonJacobstahlNum(size_t arraySize, int idxPend);
            void binarySearch();
            void printPairs() {
                    std::cout << "Current vecpairs:\n";
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
            void printMain(std::vector<std::vector<int> >main) {
                    std::cout << "Current main:\n";
                    for (size_t i = 0; i < main.size(); ++i)
                    {
                        std::cout << "(";
                        for (size_t j = 0; j < main[i].size(); ++j)
                        {
                            std::cout << main[i][j];
                            if (j < main[i].size() - 1)
                                std::cout << ", ";
                        }
                        std::cout << ")\n";
                    }
                    std::cout << "-------\n";
                }
                void printPend(std::vector<std::vector<int> > pend) {
                    std::cout << "Current pend:\n";
                    for (size_t i = 0; i < pend.size(); ++i)
                    {
                        std::cout << "(";
                        for (size_t j = 0; j < pend[i].size(); ++j)
                        {
                            std::cout << pend[i][j];
                            if (j < pend[i].size() - 1)
                                std::cout << ", ";
                        }
                        std::cout << ")\n";
                    }
                    std::cout << "-------\n";
                }
                // void dequePairs();
};

#endif // PMERGEME_HPP
