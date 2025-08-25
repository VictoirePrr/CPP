/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:45:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 16:30:36 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
}

Character::Character(const Character &copy) : ICharacter(copy) {
}

Character& Character::operator=(const Character &copy) {

    if (this != &copy)
    {
        ICharacter::operator=(copy);
    }
    return(*this); 
}


Character::~Character() {
}

std::string const& Character::getName() const {
    return(name);
}

void Character::equip(AMateria* m) {

    int idx;
    
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            idx = i;
            break;
        } 
    }
    if(_inventory[idx] == NULL && (m->getType() == "Ice" ||  m->getType() == "Cure"))
    {
        _inventory[idx] = m->clone();
    }
}

void Character::unequip(int idx) {

    
}

void Character::use(int idx, ICharacter& target) {
    _inventory[idx]->use(target); 
}
