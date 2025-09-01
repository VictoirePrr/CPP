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
    _brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}
 
Cat::Cat(const Cat &copy) : Animal(copy)  {
        type = copy.type;
         _brain = new Brain(*copy._brain);
}
    
Cat& Cat::operator=(const Cat &copy) {
        if (this != &copy)
        {
            Animal::operator=(copy);
            delete _brain;
            _brain = new Brain(*copy._brain);
        }
        return(*this);
}
    
Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called." << std::endl; 
}

void Cat::makeSound() const {
    std::cout << RED << "MIAWW !" << RESET << std::endl;
}

