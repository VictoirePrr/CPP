/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:26:19 by victoire          #+#    #+#             */
/*   Updated: 2025/08/01 14:30:29 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Default FragTrap constructor created "<< _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor copied " << _name << std::endl;      
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
        if (this != &other)
            ClapTrap::operator=(other); 
        std::cout << "FragTrap copy operator copied " << _name << std::endl;
        return (*this);         
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap construcutor created "<< _name << std::endl;  
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests: High five, guys! ✋" << std::endl;
}