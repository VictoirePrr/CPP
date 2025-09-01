/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:21:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 18:09:49 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice()  : AMateria("ice") {
}
 
Ice::Ice(const Ice &copy) : AMateria(copy){
}
    
Ice& Ice::operator=(const Ice &copy) {
    
    if (this != &copy)
    {
         AMateria::operator=(copy);
    }
    return (*this);
}
    
Ice::~Ice() {
}

AMateria* Ice::clone() const {
    return(new Ice);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}