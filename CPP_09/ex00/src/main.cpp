#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {

    if (argc != 2) {
        std::cout << "ERROR : must take a file as an argument" << std::endl;
       return 0;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cout << "ERROR : Cannot open " << argv[1] << std::endl;
        return 0;
    }

    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "ERROR : Cannot open data.csv" << std::endl;
        return 0;
    }

    BitcoinExchange BE(file);
    BE.computeBitcoinExchange(input);
    return(0);
}
