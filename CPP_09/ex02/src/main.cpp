#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    PmergeMe merge;
    size_t pairSize = 1;

    if (argc < 2){
            std::cout << "Error" << std::endl;
            return(1);
        } 

    for (int i = 1; argv[i]; i++) {
        if (merge.parseArgs(argv[i])) {
            std::cout << "Error" << std::endl;
            return(1);
        }    
    }

    if (merge.checkDuplicates()) {
            std::cout << "Error" << std::endl;
            return(1);
    }

    merge.printBefore(argv);

    clock_t vstart = clock();
    merge.vectorPairs(pairSize);
    merge.vecBinarySearch();
    clock_t vend = clock();

    merge.printAfter("vector");
    double velapsed = double(vend - vstart) / CLOCKS_PER_SEC;
    merge.printProcess(argc, velapsed, "vector");

    clock_t dstart = clock();
    merge.dequePairs(pairSize);
    merge.deqBinarySearch();
    clock_t dend = clock();

    merge.printAfter("deque");
    double delapsed = double(dend - dstart) / CLOCKS_PER_SEC;
    merge.printProcess(argc, delapsed, "deque");
    return (0);

}