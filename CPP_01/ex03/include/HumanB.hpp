/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:04:08 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 22:03:38 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
    
    private :
    
        std::string _name;
        Weapon *_weapon;
    
    public :
    
        HumanB(std::string name);
        ~HumanB();
    
        void attack(void);
        void setWeapon(Weapon &weapon);
        
    
};

#endif