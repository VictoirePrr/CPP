/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:12 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 16:41:23 by vicperri         ###   ########lyon.fr   */
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
    
};

Zombie* zombieHorde( int N, std::string name );

#endif