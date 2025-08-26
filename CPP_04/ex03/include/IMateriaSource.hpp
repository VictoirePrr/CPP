/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 16:57:18 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
  
    protected :

        std::string _type;
        AMateria *_ressource[4];

    public :

        IMateriaSource();
        IMateriaSource(const IMateriaSource &copy);
        IMateriaSource& operator=(const IMateriaSource &copy);

        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif