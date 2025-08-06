/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:23 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 11:14:36 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::Zombie(std::string name){
    _name = name;
}

void Zombie::Setname(std::string name){
    _name = name;
}

Zombie::~Zombie(){
    std::cout << _name << ": DESTROYED !"<< std::endl;
}

void Zombie::announce(){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}