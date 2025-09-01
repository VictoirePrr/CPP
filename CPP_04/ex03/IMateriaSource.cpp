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
     for (int i = 0; i < 4; i++)
        _ressource[i] = NULL;
}
 
IMateriaSource::IMateriaSource(const IMateriaSource &copy) : _type(copy._type) {
    for (int i = 0; i < 4; i++)
    {
        if (copy._ressource[i])
            _ressource[i] = copy._ressource[i]->clone();
        else
            _ressource[i] = NULL;
    }
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &copy) {
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_ressource[i])
                delete _ressource[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (copy._ressource[i])
                _ressource[i] = copy._ressource[i]->clone();
            else
                _ressource[i] = NULL;
        }
    }
    return (*this);
}
    
IMateriaSource::~IMateriaSource() {
     for (int i = 0; i < 4; i++)
     {
         if (_ressource[i])
             delete _ressource[i];
     }
}
