/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:21:41 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 15:59:47 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>


class Zombie {
    
    private:
        std::string _name;
        
    public:
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
