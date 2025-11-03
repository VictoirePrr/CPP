#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {

    (void)argv;
    if (argc != 2) {
        std::cout << "ERROR : must take a file as an argument" << std::endl;
       return 0;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cout << "ERROR : Cannot open " << argv[1] << std::endl;
        return 0;
    }

    std::ifstream file("data.csv");
    if (!file) {
        std::cout << "ERROR : Cannot open data.csv" << std::endl;
        return 0;
    }

    BitcoinExchange BE(file);
    BE.registerInput(input);
    try { 
        BE.parseInput();
    } 
    catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what()  << std::endl;
    }
    return(0);
}
