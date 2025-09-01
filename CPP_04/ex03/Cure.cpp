/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:37:32 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 18:09:43 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
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
}

AMateria* Cure::clone() const {
    return(new Cure);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds * " << std::endl;
}