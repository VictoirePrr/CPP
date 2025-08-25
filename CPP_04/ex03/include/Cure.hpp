/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:37:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 13:44:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
  
    protected :

        std::string _type;

    public :

        Cure();
        Cure(const Cure &copy);
        Cure& operator=(const Cure &copy);
        virtual ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif