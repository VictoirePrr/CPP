#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137) {
    _target = "default target"
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
         _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target) {

}

bool PresidentialPardonForm::beSigned(Bureaucrat *b) {

    if (b->getGrade() <= getSignGrade())
    {
        _signed = true;
    }
    else
        throw GradeTooLowException();
    return (_signed);

}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f) {
    os << f.getName() << ", PresidentialPardonForm require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The PresidentialPardonForm is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}