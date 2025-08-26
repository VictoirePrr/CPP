/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 11:56:26 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
     std::cout << "IMateriaSource constructor called." << std::endl;
}
 
IMateriaSource::IMateriaSource(const IMateriaSource &copy) : _type(copy._type) {

    for (int i = 0; i < 4; i++)
        {
            _ressource[i] = copy._ressource[i];
        }
        
}
    
IMateriaSource& IMateriaSource::operator=(const IMateriaSource &copy) {
    if (this != &copy)
    {
         this->_type = copy._type;
         for (int i = 0; i < 4; i++)
        {
            _ressource[i] = copy._ressource[i];
        }
    }
    return (*this);
}
    
IMateriaSource::~IMateriaSource() {
    std::cout << "IMateriaSource destructor called." << std::endl;
}
