#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
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

        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            int parseArgs(char *args);
            int checkDuplicates();
            void sortCont();

};

#endif // PMERGEME_HPP
