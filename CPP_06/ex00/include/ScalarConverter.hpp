/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:04 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 15:50:00 by vicperri         ###   ########lyon.fr   */
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
            static bool stringToDouble(const std::string& s, double& result);
            static void doubleToInt(double& result);
            static void doubleToChar(double& result);
            static bool handleSpecialString(const std::string& s);
            

};