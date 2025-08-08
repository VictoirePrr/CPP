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
    setType();
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
}

void Cat::makeSound() const {
    std::cout << "MIAWW !" << std::endl;
}

void Cat::setType() {
    type = "Cat";
}