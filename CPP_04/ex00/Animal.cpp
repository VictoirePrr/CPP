/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 14:29:52 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    
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
    
    std::cout << "I do not know which sound make " << getType() << "but probably something like 'ROUAOUUUUUUUUUURR'" << std::endl;
}

std::string Animal::getType() const {
    return(type);    
}

void Animal::setType() {
    type = "Unknown animal";
}