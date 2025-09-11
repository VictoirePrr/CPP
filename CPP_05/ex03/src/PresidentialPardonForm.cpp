/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:23 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 13:28:42 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("default target") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) 
    {
         _target = other._target;
         AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5), _target(target) {

}

void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return(_target);
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f) {
    os << f.getName() << " ( " << f.getTarget() << " ) " << ", require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. It is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}