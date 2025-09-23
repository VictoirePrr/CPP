/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:11 by victoire          #+#    #+#             */
/*   Updated: 2025/09/23 16:50:04 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
}


bool stringToIntAndChar(const std::string& s, int& result) {
    std::stringstream ss(s);
    ss >> result;

    if (ss.fail()) {
        std::cout << "char : impossible\nint : impossible" << std::endl;
        return false;
    }
    
    char nextChar = ss.peek();
    if (nextChar != EOF && nextChar != '.') {
        std::cout << "char : impossible\nint : impossible" << std::endl;
        return false;
    }
    
    if (result > 127 || result < 0)
            std::cout << "char : impossible" << std::endl;
    else if ((result >= 0 && result <= 32 ) || result == 127)
            std::cout << "char : Non displayable " << std::endl;
    else
        std::cout << "char : " << static_cast<char>(result) << std::endl;
    std::cout << "int : " << result << std::endl;
    return true;
}

bool stringToFloat(const std::string& s, float& result) {
    std::stringstream ss(s);
    ss >> result;

    if (ss.fail()) {
        std::cout << "float : impossible" << std::endl;
        return false;
    }

    char nextChar = ss.peek();
    if (nextChar != EOF && nextChar != 'f') {
        std::cout << "float : impossible" << std::endl;
        return false;
    }

     if (std::isnan(result)) {
        std::cout << "float : nan" << std::endl;
    } else if (std::isinf(result)) {
        if (std::signbit(result))
            std::cout << "float : -inf" << std::endl;
        else
            std::cout << "float : +inf" << std::endl;
    } else
    std::cout << "float : " << result << "f" << std::endl;
    return true;
}

bool stringToDouble(const std::string& s, double& result) {
    std::stringstream ss(s);
    ss >> result;

    if (ss.fail()) {
        std::cout << "double : impossible" << std::endl;
        return false;
    }

    char nextChar = ss.peek();
    if (nextChar != EOF && nextChar != 'f') {
        std::cout << "double : impossible" << std::endl;
        return false;
    }
    
    if (std::isnan(result)) {
        std::cout << "double : nan" << std::endl;
    } else if (std::isinf(result)) {
        if (std::signbit(result))
            std::cout << "double : -inf" << std::endl;
        else
            std::cout << "double : +inf" << std::endl;
    } else
    std::cout << "double : " << std::fixed << std::setprecision(1) << result << std::endl;
    return true;
}

void ScalarConverter::convert(std::string &s) {

        int num;
        stringToIntAndChar(s, num);
        float fnum;
        stringToFloat(s, fnum);
        double value;
         stringToDouble(s, value);

}