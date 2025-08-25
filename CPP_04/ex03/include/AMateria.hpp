/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 13:44:25 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#define RED   "\033[31m"
#define RESET "\033[0m"

#include "ICharacter.hpp"

class AMateria {
  
    protected :

        std::string _type;

    public :

        AMateria();
        AMateria(const AMateria &copy);
        AMateria& operator=(const AMateria &copy);
        virtual ~AMateria();

        AMateria(std::string const &type);

        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};

#endif