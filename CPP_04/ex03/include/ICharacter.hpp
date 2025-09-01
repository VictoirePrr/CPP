/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:40:11 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 10:31:32 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
class AMateria;

class ICharacter {

    protected :

        std::string name;
        AMateria *_inventory[4];
        AMateria *_ground[4];

    public :

        ICharacter(std::string c_name);
        ICharacter(const ICharacter &copy);
        ICharacter& operator=(const ICharacter &copy);
        virtual ~ICharacter();
        
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;

};

#endif