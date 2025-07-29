/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:49:05 by victoire          #+#    #+#             */
/*   Updated: 2025/07/29 16:11:22 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){   
}


ClapTrap::ClapTrap(const ClapTrap& other){
    this->_name = other._name; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if(this != &other)
        this->_name = other._name; 
    return (*this);
}

ClapTrap::~ClapTrap(){   
}

ClapTrap::ClapTrap(std::string& _name){
    //// a voir   
}

void ClapTrap::attack(const std::string& target) {
    
    std::cout << "ClapTrap" << <name> << "attacks" << <target> <<", causing" << <damage> << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

    std::cout << "ClapTrap" << <name> << "attacks" << <target> <<", causing" << <damage> << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    
    std::cout << "ClapTrap" << <name> << "attacks" << <target> <<", causing" << <damage> << "points of damage!" << std::endl;
    
}