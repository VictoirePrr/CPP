#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    PmergeMe start;
    size_t pairSize = 1;

    (void)argc;
    // if (argc == 2){
    //         std::cout << "Error" << std::endl;
    //         return(1);
    //     } 

    for (int i = 1; argv[i]; i++) {
        if (start.parseArgs(argv[i])) {
            std::cout << "Error" << std::endl;
            return(1);
        }    
    }

    if (start.checkDuplicates()) {
            std::cout << "Error" << std::endl;
            return(1);
    }
    // clock_t start = clock();
    // clock_t end = clock();
    // double elapsed = double(end - start) / CLOCKS_PER_SEC;
    start.vectorPairs(pairSize);
    start.binarySearch(pairSize);

    return (0);

}