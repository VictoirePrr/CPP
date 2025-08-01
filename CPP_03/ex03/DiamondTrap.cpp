/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:00:17 by victoire          #+#    #+#             */
/*   Updated: 2025/08/01 15:45:00 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()  {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _name = "Anonymus Diamond";
    std::cout << "Default DiamondTrap constructor created "<< _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "DiamondTrap copy constructor copied " << _name << std::endl;      
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
        if (this != &other) {
            ClapTrap::operator=(other);
            ScavTrap::operator=(other);
            FragTrap::operator=(other);  
        }
        std::cout << "DiamondTrap copy operator copied " << _name << std::endl;
        return (*this);         
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destroyed " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(), FragTrap() {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    std::cout << "DiamondTrap construcutor created "<< _name << std::endl;  
}

 void DiamondTrap::attack(const std::string& target) {
        ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My DiamondTrap name is " << _name 
    << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}