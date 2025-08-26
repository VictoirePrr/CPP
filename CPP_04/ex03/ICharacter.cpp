/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:45:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 17:00:35 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(std::string name) {
    this->name = name;
}

ICharacter::ICharacter(const ICharacter &copy) {
    for (int i = 0; i < 4; i++)
    {
        name = copy.name;
        _inventory[i] = copy._inventory[i];
        _ground[i] = copy._ground[i];
    }
}
ICharacter& ICharacter::operator=(const ICharacter &copy) {
    if (this != &copy)
    {
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            _inventory[i] = copy._inventory[i];
            _ground[i] = copy._ground[i];
        }
    }
    return(*this); 
}

ICharacter::~ICharacter() {
}
