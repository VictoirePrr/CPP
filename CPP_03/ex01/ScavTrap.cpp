/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:31:10 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/22 16:16:16 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _name = "Default Scav name";
    std::cout << "Default ScavTrap constructor created "<< _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor copied " << _name << std::endl;      
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
    {
         ClapTrap::operator=(other);    
    }
    std::cout << "ScavTrap copy operator copied " << _name << std::endl;
    return (*this);         
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor created "<< _name << std::endl;  
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << _name << " attacks " << target <<", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}