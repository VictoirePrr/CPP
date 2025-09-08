#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) {

}

bool ShrubberyCreationForm::beSigned(Bureaucrat *b)
{
    
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f) {
    os << f.getName() << ", ShrubberyCreationForm require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The ShrubberyCreationForm is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}