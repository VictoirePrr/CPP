/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:04 by victoire          #+#    #+#             */
/*   Updated: 2025/09/23 16:46:23 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>

class ScalarConverter {

        private :

            ScalarConverter();

        public :

            ScalarConverter(const ScalarConverter& other);
            ScalarConverter& operator=(const ScalarConverter& other);
            ~ScalarConverter();

            static void convert(std::string &s);

};


bool stringToIntAndChar(const std::string& s, int& result);
bool stringToDouble(const std::string& s, double& result);
bool stringToFloat(const std::string& s, float& result);