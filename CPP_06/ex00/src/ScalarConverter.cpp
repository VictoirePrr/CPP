/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:11 by victoire          #+#    #+#             */
/*   Updated: 2025/09/29 12:36:22 by vicperri         ###   ########lyon.fr   */
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


bool ScalarConverter::handleSpecialString(const std::string& s) {
    if (s == "nan" || s == "nanf" || s == "-inf" || s == "+inf" || s == "inf" 
        || s == "inff" || s == "+inff" || s == "-inff") {

        std::cout << "char : impossible" << std::endl;
        std::cout << "int : : impossible" << std::endl;
        std::cout << "float : " << ((s == "nan" || s == "nanf") ? "nanf" 
        : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inff" 
        : (s == "-inf" || s == "-inff") ? "-inff"
        : "") << std::endl;
        std::cout << "double : " << ((s == "nan" || s == "nanf") ? "nan" 
        : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inf" 
        : (s == "-inf" || s == "-inff") ? "-inf"
        : "") << std::endl;
        
        return(true);
    }
    return(false);
}

void ScalarConverter::doubleToChar(double& result) {
    
    if (result >= CHAR_MAX || result <= CHAR_MIN)
        std::cout << "char : impossible" << std::endl;
    else if ((static_cast<char>(result) >= 0 && static_cast<char>(result) <= 32 ) 
    || static_cast<char>(result) == 127)
        std::cout << "char : Non displayable " << std::endl;
    else
        std::cout << "char : " << static_cast<char>(result) << std::endl;
}

void ScalarConverter::doubleToInt(double& result) {
    if (result >= INT_MAX || result <= INT_MIN)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(result) << std::endl;
}


bool ScalarConverter::stringToDouble(const std::string& s, double& result) {
    
    std::stringstream ss(s);
    ss >> result;

    if (ss.fail()) {
        return false;
    }

    char nextChar = ss.peek();
    if (nextChar != EOF && nextChar != 'f') {
        return false;
    }
    
    if (std::isnan(result))
        handleSpecialString("nan");
    else if (std::isinf(result)) {
        if (std::signbit(result))
            handleSpecialString("-inf");
        else
            handleSpecialString("+inf");
        } 
    else {
        doubleToChar(result);
        doubleToInt(result);
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1) << result << std::endl;
    }
        
    return true;
}

void ScalarConverter::convert(std::string &s) {

    double value;
    if (handleSpecialString(s))
        return ;
        //findtypeliteral(std::string &value)
        // {
        //    size_t pos = value.find('.');
    //     if (pos != std::string::npos) {
    //          size_t pos = value.find('f');
    //       if (pos != std::string::npos)
    //                 std::string type = float;
    //        else
    //             std::string type = double;
    //}
    
    // else
    //     std::cout << "Letter not found." << std::endl;
    if (stringToDouble(s, value) == false) {
        throw ImpossibleConversion();
    }

}

const char* ScalarConverter::ImpossibleConversion::what() const throw() {
	return "char : impossible\nint : : impossible\nfloat : impossible\ndouble : impossible";
}
