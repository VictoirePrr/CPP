/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:31:10 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 13:56:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ScavTrap copy constructor called" << std::endl;
        
}

ScavTrap& ScavTrap::operator=(ScavTrap& other){
    std::cout << "ScavTrap copy operator called" << std::endl;
        if (this != &other)
        {
            this->_name = other._name;
            this->_hitPoints = other._hitPoints;
            this->_energyPoints = other._energyPoints;
            this->_attackDamage = other._attackDamage;
        }
        return (*this);
            
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _name = name; 
    std::cout << "ScavTrap construcutor created "<< _name << std::endl;  
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << _name << " attacks " << target <<", causing " << _attackDamage << " points of damage! " << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}