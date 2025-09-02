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

MateriaSource::MateriaSource() : IMateriaSource () {
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
}

void MateriaSource::learnMateria(AMateria* m) {

    int idx = -1;
    
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if(_ressource[i] == NULL)
        {
            idx = i;
            break;
        } 
    }

    if(idx != -1 && m && (m->getType() == "ice" ||  m->getType() == "cure"))
        _ressource[idx] = m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 3; i >= 0; i--) 
    {
        if (_ressource[i] && _ressource[i]->getType() == type)
            return (_ressource[i]->clone());
    }
    return 0;
}