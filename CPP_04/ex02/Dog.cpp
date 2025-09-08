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

Dog::Dog()
{
    type = "Dog";
    _ideas = new Brain();
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    _ideas = new Brain(*copy._ideas);
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete _ideas;
        _ideas = new Brain(*copy._ideas);
    }
    return (*this);
}

Dog::~Dog()
{
    delete _ideas;
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << RED << "WOUF !" << RESET << std::endl;
}
