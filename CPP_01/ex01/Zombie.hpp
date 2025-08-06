/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:12 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 11:14:31 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>

class Zombie {
    
    private :
    
        std::string _name;

    public :
    
        Zombie();
        Zombie(std::string name);
         ~Zombie();
        
        void announce(void);
        void Setname(std::string name);
    
};

Zombie* zombieHorde( int N, std::string name );

#endif