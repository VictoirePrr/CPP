/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:37:32 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 10:47:00 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
    _type = "Cure";
     std::cout << "Cure constructor called." << std::endl;
}
 
Cure::Cure(const Cure &copy) : AMateria(copy){
}
    
Cure& Cure::operator=(const Cure &copy) {
    if (this != &copy)
    {
         AMateria::operator=(copy);
    }
    return (*this);
}
    
Cure::~Cure() {
    std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const {
    AMateria *ptr = new Cure;
    return(ptr);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals" << target.getName() << "'s wounds * " << std::endl;
}