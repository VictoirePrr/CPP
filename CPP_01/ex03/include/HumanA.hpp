/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:53:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 20:36:58 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
    
    private :
    
        std::string _name;
        Weapon &_weapon;
    
    public :
    
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
    
        void attack(void);
    
};

#endif