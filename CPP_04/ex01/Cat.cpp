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
    Brain *brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}
 
Cat::Cat(const Cat &copy) {
        type = copy.type;
}
    
Cat& Cat::operator=(const Cat &copy) {
        if (this != &copy)
            type = copy.type;
        return(*this);
}
    
Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl; 
}

void Cat::makeSound() const {
    std::cout << RED << "MIAWW !" << RESET << std::endl;
}

