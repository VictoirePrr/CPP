/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:45:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/08 14:06:16 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string c_name) : ICharacter(c_name) {
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

    int idx = -1;

    if (!m)
        return;

     for (int i = 0; i < 4; i++)
        if(_inventory[i] == m)
            return ;
        
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            idx = i;
            break;
        } 
    }

    if(idx != -1 && m && (m->getType() == "cure" ||  m->getType() == "ice"))
        _inventory[idx] = m;
}

void Character::unequip(int idx) {

    if (idx < 0 || idx > 4)
        return ;
        
    if(_inventory[idx] != NULL && (_inventory[idx]->getType() == "ice" ||  _inventory[idx]->getType() == "cure"))
    {
        AMateria* tmp = _inventory[idx];
        _inventory[idx] = NULL;
        for (int i = 0; i < 4; i++)
        {
            if(_ground[i] == NULL)
            {
                _ground[i] = tmp;
                return ;
            } 
        }
        std::cout << "Ground is full !" << std::endl;
    }
    
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 &&_inventory[idx])
        _inventory[idx]->use(target); 
}