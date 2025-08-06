/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:58:41 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 14:16:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string type){
    setType(type);
}

Weapon::~Weapon(){
}

const std::string Weapon::getType(){
    std::string const &typeREF = _type;
    return(typeREF);
}
    
void Weapon::setType(std::string _new_type){
    _type = _new_type;
}