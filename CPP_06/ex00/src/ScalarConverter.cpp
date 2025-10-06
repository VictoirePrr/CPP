/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:11 by victoire          #+#    #+#             */
/*   Updated: 2025/10/06 10:05:54 by victoire         ###   ########lyon.fr   */
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
    if (nextChar != EOF && nextChar != 'f' && nextChar != 'F' && nextChar != '.') {
        return false;
    }
    return true;
}

bool ScalarConverter::handleSpecialString(const std::string &s) {
    if (s == "nan" || s == "nanf" || s == "-inf" || s == "+inf" 
        || s == "inf" || s == "inff" || s == "+inff" || s == "-inff") {

        std::cout << "char : impossible" << std::endl;
        std::cout << "int : : impossible" << std::endl;
        std::cout << "float : " << ((s == "nan" || s == "nanf") ? "nanf" 
        : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inff"                                            
        : (s == "-inf" || s == "-inff") ? "-inff"
        : "")
            << std::endl;
        std::cout << "double : " << ((s == "nan" || s == "nanf") ? "nan" 
        : (s == "inf" || s == "+inf" || s == "inff" || s == "+inff") ? "+inf"
        : (s == "-inf" || s == "-inff") ? "-inf"
         : "")
            << std::endl;

        return (true);
    }
    return (false);
}

bool ScalarConverter::convertToChar(const std::string &s, bool print) {

    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-') {
        std::cout << "char : " << static_cast<char>(s[0]) << std::endl;
        convertToInt(s, false);
        convertToFloat(s, false);
        convertToDouble(s, false);
        return true;
    }
    
    double result;
    
    std::stringstream ss(s);
    ss >> result;
    
    if (ssCheck(ss) == false)
        return (false);

    if (result >= CHAR_MAX || result <= CHAR_MIN || result < 0) {
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
    || (static_cast<char>(result) == 127)) {
         if (print) {
            std::cout << "char : Non displayable" << std::endl;
            convertToInt(s, false);
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else
            std::cout << "char : Non displayable" << std::endl;
        
    }
    
    else {
        if (print) {
            std::cout << "char print : " << static_cast<char>(result) << std::endl;
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

    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-') {
        std::cout << "int : " << static_cast<int>(s[0]) << std::endl;
    }
    
    int result;

    std::stringstream ss(s);
    ss >> result;

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
    if (ssCheck(ss) == false)
        return (false);
    else {
        if (print) {
            convertToChar(s, false);
            std::cout << "int : " << static_cast<int>(result) << std::endl;
            convertToFloat(s, false);
            convertToDouble(s, false);
        }
        else {
              std::cout << "int : " << static_cast<int>(result) << std::endl;
        }
    }
    return true;
}

bool ScalarConverter::convertToFloat(const std::string &s, bool print) {

    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-') {
        std::cout << "float : " << std::fixed << std::setprecision(1)
         << static_cast<float>(s[0]) << "f" << std::endl;
    }
    
    float result;

    std::stringstream ss(s);
    ss >> result;

    if (std::isnan(result))
        handleSpecialString("nan");
    else if (std::isinf(result)) {
        if (std::signbit(result))
            handleSpecialString("-inf");
        else
            handleSpecialString("+inf");
    }
    
    if (ssCheck(ss) == false)
        return (false);

    if (result >= FLT_MAX || result < -FLT_MAX) {
        if (print)  {
            convertToChar(s, false);
            convertToInt(s, false);
            std::cout << "float : impossible" << std::endl;
            convertToDouble(s, false);
        }
        else
            std::cout << "float : impossible" << std::endl;
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


    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-') {
        std::cout << "double : " << std::fixed << std::setprecision(1) 
        << static_cast<double>(s[0]) << std::endl;
    }
    
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
            break;
        default:
            throw ImpossibleConversion();
            break;
    }
}

std::string ScalarConverter::findLiteralType(std::string &value) {

    if (value.empty())
        return "";

    if (value.size() == 1 && !std::isdigit(static_cast<unsigned char>(value[0])))
        return "Char";

    size_t i = 0;
    if (value[i] == '+' || value[i] == '-')
        i++;

    bool hasDot = false;
    bool hasF = false;
    bool hasDigit = false;

    for (; i < value.size(); i++) {
        char c = value[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else if (c == '.') {
            if (hasDot)
                return "";
            hasDot = true;
        } else if ((c == 'f' || c == 'F') && i == value.size() - 1) {
            hasF = true;
        } else {
            return "";
        }
    }

    if (!hasDigit)
        return "";
    if (hasDot && hasF)
        return "Float";
    else if (hasDot)
        return "Double";
    else if (!hasDot && !hasF)
        return "Int";

    return "";
}

const char *ScalarConverter::ImpossibleConversion::what() const throw() {
    return "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible";
}
