/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:32 by victoire          #+#    #+#             */
/*   Updated: 2025/09/16 12:45:26 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),  _target("default target"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
    _target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) 
    {
        _target = other._target;
         AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

void ShrubberyCreationForm::executeAction() const {
    std::string outputFilename =  _target + "_shrubbery";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cout << "Failed to open the output file." << std::endl;
        return;
    }
    outputFile << "                *\n";
    outputFile << "               /|\\\n";
    outputFile << "              //|\\\\\n";
    outputFile << "             ///|\\\\\\\n";
    outputFile << "            ////|\\\\\\\\\n";
    outputFile << "           /////|\\\\\\\\\\\n";
    outputFile << "          //////|\\\\\\\\\\\\\n";
    outputFile << "         ///////|\\\\\\\\\\\\\\\n";
    outputFile << "        ////////|\\\\\\\\\\\\\\\\\n";
    outputFile << "               |||\n";
    outputFile << "               |||\n";
    outputFile << "            ___|||___\n";
    outputFile << "           /   | |   \\\n";
    outputFile << "          /____|_|____\\\n";
    outputFile.close();

}

std::string ShrubberyCreationForm::getTarget() const {
    return(_target);
}


std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f) {
    os << f.getName() << " ( " << f.getTarget() << " ) " << ", require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. It is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}