/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:11 by victoire          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:34 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

bool ScalarConverter::ssCheck(std::stringstream &ss) {
    if (ss.fail()) {
        return false;
    }
    char nextChar = ss.peek();
    if (nextChar != EOF && nextChar != 'f') {
        return false;
    }
    return true;
}

bool ScalarConverter::handleSpecialString(const std::string &s)
{
    if (s == "nan" || s == "nanf" || s == "-inf" || s == "+inf" || s == "inf" || s == "inff" || s == "+inff" || s == "-inff")
    {

        std::cout << "char : impossible" << std::endl;
        std::cout << "int : : impossible" << std::endl;
        std::cout << "float : " << ((s == "nan" || s == "nanf") ? "nanf" : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inff"
                                                                       : (s == "-inf" || s == "-inff")                                ? "-inff"
                                                                                                                                      : "")
                  << std::endl;
        std::cout << "double : " << ((s == "nan" || s == "nanf") ? "nan" : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inf"
                                                                       : (s == "-inf" || s == "-inff")                                ? "-inf"
                                                                                                                                      : "")
                  << std::endl;

        return (true);
    }
    return (false);
}

bool ScalarConverter::convertToChar(const std::string &s, bool print) {

    char result;

    std::stringstream ss(s);
    ss >> result;

    if (ssCheck(ss) == false)
        return (false);

    if (result >= CHAR_MAX || result <= CHAR_MIN) {
        if (print) {
            std::cout << "char : impossible" << std::endl;
            convertToInt(s, false);
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "char : impossible" << std::endl;
    }
    else if ((static_cast<char>(result) >= 0 && static_cast<char>(result) <= 32) 
    || static_cast<char>(result) == 127) {
         if (print) {
            std::cout << "char : Non displayable " << std::endl;
            convertToInt(s, false);
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "char : Non displayable " << std::endl;
        
    }
    
    else {
        if (print) {
            std::cout << "char : " << static_cast<char>(result) << std::endl;
            convertToInt(s, false);
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "char : " << static_cast<char>(result) << std::endl;
    }
    return true;
}

bool ScalarConverter::convertToInt(const std::string &s, bool print) {

    int result;

    std::stringstream ss(s);
    ss >> result;

    if (ssCheck(ss) == false)
        return (false);

    if (result >= INT_MAX || result <= INT_MIN) {
        if (print)  {
            convertToChar(s, false);
            std::cout << "int : impossible" << std::endl;
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "int : impossible" << std::endl;
    }
    
    else {
        if (print) {
            convertToChar(s, false);
            std::cout << "int : " << static_cast<int>(result) << std::endl;
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "int : " << static_cast<int>(result) << std::endl;
    }
    return true;
}

bool ScalarConverter::convertToFloat(const std::string &s, bool print) {

    float result;

    std::stringstream ss(s);
    ss >> result;

    if (ssCheck(ss) == false)
        return (false);

    if (std::isnan(result))
        handleSpecialString("nan");
    else if (std::isinf(result)) {
        if (std::signbit(result))
            handleSpecialString("-inf");
        else
            handleSpecialString("+inf");
    }
    
    else {
        if (print) {
            convertToChar(s, false);
            convertToInt(s, false);
            std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
            convertToDouble(s, false);
        }
        else
            std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
    }
    return true;
}

bool ScalarConverter::convertToDouble(const std::string &s, bool print) {

    double result;
    std::stringstream ss(s);
    ss >> result;

    if (ssCheck(ss) == false)
        return (false);

    if (std::isnan(result))
        handleSpecialString("nan");
    else if (std::isinf(result)) {
        if (std::signbit(result))
            handleSpecialString("-inf");
        else
            handleSpecialString("+inf");
    }
    
    else {
        if (print) {
            convertToChar(s, false);
            convertToInt(s, false);
            convertToFloat(s, false);
            std::cout << "double : " << std::fixed << std::setprecision(1) << result << std::endl;
        }
        else
            std::cout << "double : " << std::fixed << std::setprecision(1) << result << std::endl;
    }
    return true;
}

void ScalarConverter::convert(std::string &s) {
    
    int i = 0;
    enum lvl { Char, Int, Float, Double };
    std::string compare[] = { "Char", "Int", "Float", "Double" };
    
    if (handleSpecialString(s))
        return ;

    std::string type = findLiteralType(s);
    
    if (type.empty())
        throw ImpossibleConversion();

    while (i < 4) {
        if (compare[i] == type)
            break;
        i++;
    }

    switch (i) {

        case Char: convertToChar(s, true);
            break;
        case Int: convertToInt(s, true);
            break;
        case Float: convertToFloat(s, true);
            break;
        case Double: convertToDouble(s, true);
        default:
            throw ImpossibleConversion();
            break;
    }
}

std::string ScalarConverter::findLiteralType(std::string &value) {

    for (int i = 0; value[i]; i++){
        if (!std::isprint(value[i]))
            return (NULL);
    }

    for (int i = 0; value[i]; i++) {
        if (!std::isalpha(value[i]))
            break;
        if (i == value.length())
            ;
        return ("Char");
    }

    for (int i = 0; value[i]; i++) {
        if (!std::isdigit(value[i]))
            return (NULL);
    }

    size_t pos = value.find('.');
    if (pos != std::string::npos)
        size_t pos = value.find('f');
    else
        return ("Int");

    if (pos != std::string::npos)
        return ("Float");
    else
        return ("Double");
}

const char *ScalarConverter::ImpossibleConversion::what() const throw() {
    return "char : impossible\nint : : impossible\nfloat : impossible\ndouble : impossible";
}
