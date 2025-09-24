/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:53:44 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 11:28:35 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade) 
: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    _signed = false;
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

bool Form::beSigned(Bureaucrat const &b) {

    if (b.getGrade() <= getSignGrade())
        _signed = true;
    else
        throw GradeTooLowException();
    return (_signed);

}

const char* Form::GradeTooHighException::what() const throw () {
	return "Grade is too hight";
}

const char* Form::GradeTooLowException::what() const throw () {
	return "Grade is too low";
}