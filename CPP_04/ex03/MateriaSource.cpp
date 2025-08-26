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
 
MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy) {
}
    
MateriaSource& MateriaSource::operator=(const MateriaSource &copy) {
    if (this != &copy)
    {
         IMateriaSource::operator=(copy);
    }
    return (*this);
}
    
MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called." << std::endl;
}


void MateriaSource::learnMateria(AMateria* m) {

    int idx;
    
    for (int i = 0; i < 4; i++)
    {
        if(_ressource[i] == NULL)
        {
            idx = i;
            break;
        } 
    }
    if(_ressource[idx] == NULL && (m->getType() == "Ice" ||  m->getType() == "Cure"))
    {
        _ressource[idx] = m->clone();
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {

    for (int i = 4; i > 4; i--)
    {
        if(_ressource[i]->getType() == type)
        {
            return(_ressource[i]);
        } 
    }
    return(0);

}