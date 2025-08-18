/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:58:41 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/18 15:00:37 by vicperri         ###   ########lyon.fr   */
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

const std::string &Weapon::getType(){
    return(_type);
}
    
void Weapon::setType(std::string _new_type){
    _type = _new_type;
}