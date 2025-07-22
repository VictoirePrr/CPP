/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:53:31 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 20:25:41 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

    private :
    
        std::string _type;

    public :
    
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    
    const std::string getType();
    
    void setType(std::string _new_type);
    
};

#endif