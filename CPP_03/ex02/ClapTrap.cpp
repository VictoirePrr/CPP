/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:49:05 by victoire          #+#    #+#             */
/*   Updated: 2025/08/01 15:46:04 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
        
ClapTrap::ClapTrap(){
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    _name = "Anonymus";
    std::cout << "ClapTrap construcutor created "<< _name << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ClapTrap copy construcutor copied "<< _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if(this != &other)
     { 
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
     }
    std::cout << "ClapTrap copy operator copied "<< _name << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap(){   
    std::cout << "ClapTrap destroyed "<< _name << std::endl;
}

ClapTrap::ClapTrap(std::string name){
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    _name = name; 
    std::cout << "ClapTrap constructor created "<< _name << std::endl;  
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints <= 0 || _hitPoints <= 0)
        std::cout << "ClapTrap " << _name 
        << " doesn´t have any points left to attack!" << std::endl;
    else 
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " 
        << target <<", causing " << _attackDamage << " points of damage! " << std::endl;

    }
}

void ClapTrap::takeDamage(unsigned int amount){
    _attackDamage = amount;
    _hitPoints -= _attackDamage;
    if (_energyPoints <= 0 || _hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " take " << amount << " damage and has now " << _hitPoints << " points of health! " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0 || _hitPoints <= 0)
        std::cout << "ClapTrap " << _name 
        << " doesn´t have any points left to get repaired!" << std::endl;
    else
    { 
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repaired itself with " 
        << amount <<" points, restoring its health to " << _hitPoints << std::endl;
    }
    
}