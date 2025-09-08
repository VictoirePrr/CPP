/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:15:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/08 11:45:37 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* v = new Cat();
    delete j;
    delete i;
    
    std::cout << v->getType() << std::endl;
    return 0;
    const Animal* tab[4];
    std::cout << RED << "Filling animal with Dog..." << RESET << std::endl;
    for(int k = 0; k < 2; k++)
    {
        tab[k] = new Dog;
    }
    std::cout << RED << "Filling animal with Cat..." << RESET << std::endl;
    for(int k = 2; k < 4; k++)
    { 
        tab[k] = new Cat;
    }
    tab[1]->makeSound();
    tab[3]->makeSound();
    std::cout << RED << "Deleting animal..." << RESET << std::endl;
    for(int k = 0; k < 4; k++)
    {
        delete tab[k];
    }
    return 0;
}
