/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:20:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 13:44:04 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
  
    protected :

        std::string _type;

    public :

        Ice();
        Ice(const Ice &copy);
        Ice& operator=(const Ice &copy);
        virtual ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif