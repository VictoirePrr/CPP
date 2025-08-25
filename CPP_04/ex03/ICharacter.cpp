/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:45:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 16:33:18 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() {
}

ICharacter::ICharacter(const ICharacter &copy) {
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = copy._inventory[i];
    }
}
ICharacter& ICharacter::operator=(const ICharacter &copy) {
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            _inventory[i] = copy._inventory[i];
        }
    }
    return(*this); 
}

ICharacter::ICharacter(std::string name) {
    this->name = name;
}

ICharacter::~ICharacter() {
}
