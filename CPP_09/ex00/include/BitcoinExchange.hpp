#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

class BitcoinExchange {

        private :
            std::map<std::string, double> _db;
            std::map<std::string, double> _input;
            BitcoinExchange();

        public :

        class WrongInputException : public std::exception {
				public:
					const char *what() const throw();
			};

            BitcoinExchange(std::ifstream &file);
            BitcoinExchange(const BitcoinExchange& other);
            BitcoinExchange& operator=(const BitcoinExchange& other);
            ~BitcoinExchange();

            double getRate(const std::string& date) const;
            void registerInput(std::ifstream &file);
            void parseInput();

};

#endif // BITCOINEXCHANGE_HPP
