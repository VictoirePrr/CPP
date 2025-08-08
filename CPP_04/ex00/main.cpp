/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:15:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/08 13:15:40 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Subject Tests ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound
    j->makeSound(); // will output the dog sound
    meta->makeSound(); // base Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Additional Tests: Polymorphism ===" << std::endl;
    Animal* animals[4];
    for (int k = 0; k < 2; k++)
        animals[k] = new Dog();
    for (int k = 2; k < 4; k++)
        animals[k] = new Cat();

    for (int k = 0; k < 4; k++)
        animals[k]->makeSound();

    for (int k = 0; k < 4; k++)
        delete animals[k];

    std::cout << "\n=== WrongAnimal Tests (No Virtual Functions) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // will display WrongAnimal sound if no virtual keyword is used
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Direct WrongCat Test ===" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // should display WrongCat sound (no polymorphism here)

    return 0;
}
