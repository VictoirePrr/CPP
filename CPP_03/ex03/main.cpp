/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 09:20:40 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"

int main() {
    std::cout << RED << "\n--- Creating DiamondTrap Iris ---\n" << RESET;
    DiamondTrap iris("Iris");
    iris.attack("a grumpy goblin");
    iris.takeDamage(20);
    iris.beRepaired(15);
    iris.whoAmI();

    std::cout << RED << "\n--- Creating DiamondTrap Felix ---\n" << RESET;
    DiamondTrap felix("Felix");
    felix.attack("a cursed vending machine");
    felix.whoAmI();

    std::cout << RED << "\n--- Creating DiamondTrap Manon ---\n" << RESET;
    DiamondTrap manon("Manon");
    manon.takeDamage(50);
    manon.beRepaired(30);
    manon.attack("a jealous ClapTrap");
    manon.whoAmI();

    std::cout << RED << "\n--- Creating DiamondTrap Arthur ---\n" << RESET;
    DiamondTrap arthur("Arthur");
    arthur.attack("an innocent wall");
    arthur.whoAmI();

    std::cout << RED << "\n Test Completed Successfully!\n" << RESET;

    return 0;
}



