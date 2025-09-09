#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm A"), _signed(false), 
_signGrade(10), _execGrade(75) {

}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) 
: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
}


AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
 _signGrade(other._signGrade), _execGrade(other._execGrade) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", Aform require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The Aform is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}

const std::string AForm::getName() const {
    return(_name);
}

bool AForm::isSigned() const {
    return(_signed);
}

int AForm::getSignGrade() const {
    return(_signGrade);
}

int AForm::getExecGrade() const {
    return(_execGrade);
}

bool AForm::beSigned(Bureaucrat *b) {

    if (b->getGrade() <= getSignGrade())
    {
        _signed = true;
    }
    else
        throw GradeTooLowException();
    return (_signed);

}

void AForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        GradeTooLowException();
    executeAction();
}