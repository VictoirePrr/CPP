/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:31:07 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 13:55:32 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.cpp"

class ScavTrap : public ClapTrap {
    
    private :

    public :
    
    ScavTrap();
    ScavTrap(ScavTrap& other);
    ScavTrap& operator=(ScavTrap& other);
    ~ScavTrap();

    ScavTrap(std::string name);
    void attack(const std::string& target);
    void guardGate();
    
    
};

#endif