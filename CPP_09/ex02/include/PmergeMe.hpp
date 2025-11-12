#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

class PmergeMe {

        private :

            std::vector<int> vec;

        public :

            PmergeMe();
            PmergeMe(const PmergeMe& other);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();

            void parseArgs(std::string &args);
            void fillCont(std::string &args);
            void sortCont();

};

#endif // PMERGEME_HPP
