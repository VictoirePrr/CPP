#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form A"), _signed(false), 
_signGrade(10), _execGrade(75) {

}

Form::Form(const std::string name, const int signGrade, const int execGrade) 
: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
 _signGrade(other._signGrade), _execGrade(other._execGrade) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", form require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The form is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}

const std::string Form::getName() const {
    return(_name);
}

bool Form::isSigned() const {
    return(_signed);
}

int Form::getSignGrade() const {
    return(_signGrade);
}

int Form::getExecGrade() const {
    return(_execGrade);
}

bool Form::beSigned(Bureaucrat *b) {

    if (b->getGrade() <= getSignGrade())
    {
        _signed = true;
    }
    else
        throw GradeTooLowException();
    return (_signed);

}