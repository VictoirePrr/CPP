/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:37:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/01 11:10:02 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
  

    public :

        Cure();
        Cure(const Cure &copy);
        Cure& operator=(const Cure &copy);
        virtual ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif