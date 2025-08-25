/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 11:56:26 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
     type = "Unknown animal";
     std::cout << "Animal constructor called." << std::endl;
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
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const {
    return(type);
}
