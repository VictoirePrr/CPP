/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:20:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 11:10:06 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

    public :

        Ice();
        Ice(const Ice &copy);
        Ice& operator=(const Ice &copy);
        virtual ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif