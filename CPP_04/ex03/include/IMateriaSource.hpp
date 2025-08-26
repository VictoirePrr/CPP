/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/26 10:51:21 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

#define RED   "\033[31m"
#define RESET "\033[0m"

#include "AMateria.hpp"

class IMateriaSource {
  
    protected :

        std::string _type;

    public :

        IMateriaSource();
        IMateriaSource(const IMateriaSource &copy);
        IMateriaSource& operator=(const IMateriaSource &copy);
        virtual ~IMateriaSource();

        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif