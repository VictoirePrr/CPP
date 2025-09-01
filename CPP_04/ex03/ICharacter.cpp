/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:45:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 18:07:52 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::ICharacter(std::string c_name) {
    name = c_name;
    
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
        _ground[i] = NULL;
    }
}

ICharacter::ICharacter(const ICharacter &copy) {
    name = copy.name;
    
    for (int i = 0; i < 4; i++)
        {
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
            if (copy._ground[i])
                _ground[i] = copy._ground[i]->clone();
            else
                _ground[i] = NULL;
    }
}

ICharacter& ICharacter::operator=(const ICharacter &copy) {
    if (this != &copy)
    {
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (_ground[i])
                delete _ground[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
            if (copy._ground[i])
                _ground[i] = copy._ground[i]->clone();
            else
                _ground[i] = NULL;
        }   
    }
    return(*this); 
}

ICharacter::~ICharacter() {
     for (int i = 0; i < 4; i++)
     {
         if (_inventory[i])
             delete _inventory[i];
         if (_ground[i])
             delete _ground[i];
     }
}

