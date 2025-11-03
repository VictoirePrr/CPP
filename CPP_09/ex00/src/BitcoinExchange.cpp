#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file) {

    isFirstLine = true;

    std::string line;
    while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    double rate;
    if (std::getline(ss, date, ',') && ss >> rate)
        _db[date] = rate;
    }
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
//     //to do
// }

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
//     if (this != &other) {
//  //to do
//     }
//     return *this;
// }

BitcoinExchange::~BitcoinExchange() {
}

int BitcoinExchange::checkSep(std::string &line) {

        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (i == 11)
                if (c != '|'){
                    std::cout << "Error: bad input => " << line << std::endl;
                    return -1;
                }
        }
        return 0;
}

int BitcoinExchange::checkDate(const std::string& date) {
    if (isFirstLine) {
        isFirstLine = false;
        return -1;
    }
    struct tm tm = {};
    char* ret = strptime(date.c_str(), "%Y-%m-%d", &tm);
    if (ret == NULL) {
        std::cout << "Error: bad input => " << date << std::endl;
        return -1;
    }
    return 0;
}


void BitcoinExchange::computeBitcoinExchange(std::ifstream &file) {

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        if (std::getline(ss, date, '|')) {
            if(checkDate(date) == -1 || checkSep(line) == -1)
                continue;
            if (ss >> _value)
                _value = checkValue();
            else {
                _value = 0;
                _value = checkValue();
            }
            _rate = getRate(date);
            if (_value == -1.0 || _rate == -1.0) 
                continue;
            _result = _rate * _value;
            std::cout << date << "=> " << _value << " = " << _result << std::endl;
        }
    }
}

double BitcoinExchange::getRate(const std::string& date) const {
    itType it = _db.find(date);
    if (it != _db.end() && it->first == date) {
        return it->second;
    }
    it = _db.lower_bound(date);
    if (it == _db.begin()) {
        std::cout << "Error : no date available in the DB." << std::endl;
        return -1.0;
    }
    --it;
    return it->second;
}

double BitcoinExchange::checkValue() const {

    if (_value > 1000.0) {
            std::cout << "Error: too large a number." << std::endl;
            return -1.0;
    }
    if (_value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return -1.0;
    }
    if (_value == 0) {
            std::cout << "Error: no value retrieved." << std::endl;
            return -1.0;
    }
    // if (!std::isdigit(_value)){
    //         std::cout << "Error: bad input 2=> " << _value << std::endl;
    //         return -1.0;
    // }
    return _value;
}
