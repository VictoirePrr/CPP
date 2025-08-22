/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/22 15:58:01 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"

#include <iostream>
#include "ScavTrap.hpp"

int main() {
    std::cout << RED << "=== ClapTrap Test Begins ===" << RESET << std::endl;

    ClapTrap manon("Manon");

    std::cout << RED << "\n-- Action Phase --" << RESET << std::endl;
    manon.attack("zombie");
    manon.takeDamage(3);
    manon.beRepaired(5);
    manon.attack("vampire");
    manon.takeDamage(15);
    manon.beRepaired(5);
    manon.attack("bear");
   
    std::cout << RED << "=== ScavTrap Test Begins ===" << RESET << std::endl;

    ScavTrap felix("Felix");

    std::cout << RED << "\n-- Action Phase --" << RESET << std::endl;
    felix.attack("Xavier Dupont de Ligonnes");
    felix.takeDamage(25);
    felix.beRepaired(10);
    felix.guardGate();

    std::cout << RED << "\n=== Test Ends ===" << RESET << std::endl;
    return 0;
}


