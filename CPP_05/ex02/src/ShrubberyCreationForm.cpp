#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
    _target = "default target";
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
    std::string outputFilename =  _target + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cout << "Failed to open the output file." << std::endl;
        return;
    }
    outputFile << "   *\n";
    outputFile << "  /|\\\n";
    outputFile << " / | \\\n";
    outputFile << "   |\n";
    outputFile << "  / \\\n";
    outputFile.close();

}


std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f) {
    os << f.getName() << ", ShrubberyCreationForm require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The ShrubberyCreationForm is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}