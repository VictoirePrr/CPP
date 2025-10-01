/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:04 by victoire          #+#    #+#             */
/*   Updated: 2025/10/01 13:33:16 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>

class ScalarConverter {

        private :

            ScalarConverter();

        public :
        
             class ImpossibleConversion : public std::exception {
				public:
					const char *what() const throw();
			};

            ScalarConverter(const ScalarConverter& other);
            ScalarConverter& operator=(const ScalarConverter& other);
            ~ScalarConverter();

            static void convert(std::string &s);
            static bool convertToDouble(const std::string &s, bool print);
            static bool convertToFloat(const std::string &s, bool print);
            static bool convertToInt(const std::string &s, bool print);
            static bool convertToChar(const std::string &s, bool print);
            static bool handleSpecialString(const std::string& s);
            static std::string findLiteralType(std::string &value);
            static bool ssCheck(std::stringstream &ss);
            

};