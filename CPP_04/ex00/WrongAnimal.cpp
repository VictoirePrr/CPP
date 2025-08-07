/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 14:29:52 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    
}
 
WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
         type = copy.type;
}
    
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
    if (this != &copy)
         type = copy.type;
    return (*this);
}
    
WrongAnimal::~WrongAnimal() {
        
}

void WrongAnimal::makeSound() const {
    
    std::cout << "AHHHHHHHHHHHHHHHH" << std::endl;
}

std::string WrongAnimal::getType() const {
    return(type);    
}

void WrongAnimal::setType() {
    type = "Humain";
}