/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 11:31:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"


Cat::Cat() {
    type = "Cat";
}
 
Cat::Cat(const Cat &copy) : Animal(copy) {
        type = copy.type;
}
    
Cat& Cat::operator=(const Cat &copy) {
        if (this != &copy)
        {
            Animal::operator=(copy);
        }
        return(*this);
}
    
Cat::~Cat() {    
}

void Cat::makeSound() const {
    std::cout << RED << "MIAWW !" << RESET << std::endl;
}

