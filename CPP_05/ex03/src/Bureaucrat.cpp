/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:49 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 11:32:42 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm &f) {

    try {
        if (f.beSigned(*this))
            std::cout << getName() << " signed " << f.getName() << std::endl;

    }
    catch (std::exception &e) {
        std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {

    try {
        if (form.execute(*this))
            std::cout << getName() << " executed " << form.getName() << std::endl;

    }
    catch (std::exception &e) {
        std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
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