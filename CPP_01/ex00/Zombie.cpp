/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:21:37 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/16 13:08:43 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
            _name = name;
        }
        
Zombie::~Zombie(){
             std::cout << _name << ": DESTROYED !"<< std::endl;
        }
       
void Zombie::announce(void){
            std::cout << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
        }
