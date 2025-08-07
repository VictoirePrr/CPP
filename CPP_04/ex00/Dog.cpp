/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 11:31:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() {
}
 
Dog::Dog(const Dog &copy) {
        type = copy.type;
}
    
Dog& Dog::operator=(const Dog &copy) {
        if (this != &copy)
            type = copy.type;
        return(*this);
}
    
Dog::~Dog() {    
}

void Dog::makeSound() const {
    std::cout << "WOUF !" << std::endl;
}

void Dog::setType() {
    type = "Dog";
}
