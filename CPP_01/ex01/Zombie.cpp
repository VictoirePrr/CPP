/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:23 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/18 10:29:28 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
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