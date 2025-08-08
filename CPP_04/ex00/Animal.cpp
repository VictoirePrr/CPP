/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/08 13:14:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
     type = "Unknown animal";
}
 
Animal::Animal(const Animal &copy) {
         type = copy.type;
}
    
Animal& Animal::operator=(const Animal &copy) {
    if (this != &copy)
         type = copy.type;
    return (*this);
}
    
Animal::~Animal() {
        
}

void Animal::makeSound() const {
    
    std::cout << "An " << getType() << " but probably sound like " << RED << "'ROUAOUUUUUURR'" << RESET << std::endl;
}

std::string Animal::getType() const {
    return(type);
}

void Animal::setType() {
    type = "Unknown animal";
}