/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:21:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 10:47:20 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice() {
    _type = "ice";
     std::cout << "Ice constructor called." << std::endl;
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
    std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const {
    AMateria *ptr = new Ice;
    return(ptr);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}