#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file) {

    std::string line;
    while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    double rate;
    if (std::getline(ss, date, ',') && ss >> rate)
        _db[date] = rate;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    //to do
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
 //to do
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::registerInput(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    double value;
    if (std::getline(ss, date, '|') && ss >> value)
        _input[date] = value;
    }
}

void parseInput() {
    // do something with input
    //     size_t pos = line.find('|');
    // if (pos == std::string::npos)
    //     throw WrongInputException();
}

const char* BitcoinExchange::WrongInputException::what() const throw() {
	return "Input file must use the following format: ""date | value""";
}