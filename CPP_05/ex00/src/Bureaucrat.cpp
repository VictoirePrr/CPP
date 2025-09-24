#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat Vic"), _grade(75) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),  _grade (other._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (_grade > 150)
        throw GradeTooLowException();
    if (_grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++; 
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw () {
	return "Grade is too hight";
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return "Grade is too low";	
}

