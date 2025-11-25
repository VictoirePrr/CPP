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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    _db = other._db;
    _value = other._value;
    _rate = other._rate;
    _result = other._result;
    isFirstLine = other.isFirstLine;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
    {
        _db = other._db;
        _value = other._value;
        _rate = other._rate;
        _result = other._result;
        isFirstLine = other.isFirstLine;
    }
    return *this;
}

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

        int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;

    if (year < 2009 || year > 2025) {
        std::cout << "Error: year out of range => " << date << std::endl;
        return -1;
    }
    if (year == 2009) {
        if (month < 1 || (month == 1 && day < 3)) {
            std::cout << "Error: date before Bitcoin launch => " << date << std::endl;
            return -1;
        }
    }
    if (month < 1 || month > 12) {
        std::cout << "Error: month out of range => " << date << std::endl;
        return -1;
    }

    int maxDay;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        case 2:
            maxDay = isLeapYear(year) ? 29 : 28;
            break;
        default:
            maxDay = 0;
    }

    if (day < 1 || day > maxDay) {
        std::cout << "Error: day out of range => " << date << std::endl;
        return -1;
    }

    if (year == 2025) {
        if (month > 11 || (month == 11 && day > 25)) {
            std::cout << "Error: date beyond today => " << date << std::endl;
            return -1;
        }
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
    return _value;
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
