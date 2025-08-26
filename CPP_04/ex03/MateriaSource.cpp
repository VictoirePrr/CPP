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

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
     std::cout << "MateriaSource constructor called." << std::endl;
}
 
MateriaSource::MateriaSource(const MateriaSource &copy) : _type(copy._type) {
}
    
MateriaSource& MateriaSource::operator=(const MateriaSource &copy) {
    if (this != &copy)
    {
         this->_type = copy._type;
    }
    return (*this);
}
    
MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called." << std::endl;
}


void MateriaSource::learnMateria(AMateria*) {

}

AMateria* MateriaSource::createMateria(std::string const & type) {

}