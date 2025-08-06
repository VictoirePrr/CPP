/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:06:34 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 14:17:43 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name){
    _name = name;
    _weapon = NULL;
}

HumanB::~HumanB(){
}

void HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;
}

void HumanB::attack(){
    if(_weapon->getType().empty())
         std::cout << _name << " attacks bare handed" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
