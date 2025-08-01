/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/01 14:55:31 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"

int main() {

    std::cout << RED << "=== ClapTrap Test Begins ===" << RESET << std::endl;

    ClapTrap manon("Manon");

    std::cout << RED << "\n-- Action Phase --" << RESET << std::endl;
    manon.attack("cardboard dummy");
    manon.takeDamage(3);
    manon.beRepaired(5);
    manon.attack("practice bot");
    manon.takeDamage(15);
    manon.beRepaired(5);
    manon.attack("training drone");
    
    std::cout << RED << "=== ScavTrap Test Begins ===" << RESET << std::endl;

    ScavTrap felix("Felix");

    std::cout << RED << "\n-- Action Phase --" << RESET << std::endl;
    felix.attack("rusty target");
    felix.takeDamage(25);
    felix.beRepaired(10);
    felix.guardGate();
    
    std::cout << RED << "=== FragTrap Test Begins ===" << RESET << std::endl;

    FragTrap iris("Iris");

    std::cout << RED << "\n-- Action Phase -- " << RESET << std::endl;
    iris.attack("training dummy");
    iris.takeDamage(20);
    iris.beRepaired(15);
    iris.highFivesGuys();

    std::cout << RED << "\n=== Test Ends === " << RESET << std::endl;
    return 0;
}



