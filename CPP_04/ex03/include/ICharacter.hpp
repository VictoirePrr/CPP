/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:40:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 10:48:16 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter {

    protected :

        std::string name;
        AMateria *_inventory[4];
        AMateria *_ground[4];

    public :

        ICharacter();
        ICharacter(const ICharacter &copy);
        ICharacter& operator=(const ICharacter &copy);
        virtual ~ICharacter();
        
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;

};

#endif