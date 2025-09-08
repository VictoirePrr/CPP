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
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
    _ideas = new Brain();
}
 
Cat::Cat(const Cat &copy) : Animal(copy)  {
         _ideas = new Brain(*copy._ideas);
}
    
Cat& Cat::operator=(const Cat &copy) {
        if (this != &copy)
        {
            Animal::operator=(copy);
            delete _ideas;
            _ideas = new Brain(*copy._ideas);
        }
        return(*this);
}
    
Cat::~Cat() {
    delete _ideas;
    std::cout << "Cat destructor called." << std::endl; 
}

void Cat::makeSound() const {
    std::cout << RED << "MIAWW !" << RESET << std::endl;
}

