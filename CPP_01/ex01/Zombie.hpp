/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:12 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/19 09:56:33 by vicperri         ###   ########lyon.fr   */
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
        ~Zombie();
        
        void announce(void);
        void setName(std::string name);
    
};

Zombie* zombieHorde( int N, std::string name );

#endif