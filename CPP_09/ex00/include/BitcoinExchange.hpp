#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <ctime>

class BitcoinExchange {

        private :
            std::map<std::string, double> _db;
            bool isFirstLine;
            double _rate;
            double _value;
            double _result;
            BitcoinExchange();

            typedef std::map<std::string, double>::const_iterator itType;

        public :

            BitcoinExchange(std::ifstream &file);
            BitcoinExchange(const BitcoinExchange& other);
            BitcoinExchange& operator=(const BitcoinExchange& other);
            ~BitcoinExchange();

            double getRate(const std::string& date) const;
            double checkValue() const;
            int checkSep(std::string &line);
            void computeBitcoinExchange(std::ifstream &file);
            int checkDate(const std::string& date);
};

#endif // BITCOINEXCHANGE_HPP
