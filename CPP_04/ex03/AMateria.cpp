/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 11:56:26 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
     std::cout << "AMateria constructor called." << std::endl;
}
 
AMateria::AMateria(const AMateria &copy) : _type(copy._type) {
}
    
AMateria& AMateria::operator=(const AMateria &copy) {
    if (this != &copy)
    {
         this->_type = copy._type;
    }
    return (*this);
}
    
AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) :  _type(type) {
}

std::string const&  AMateria::getType() const {
        return(_type);
}

void AMateria::use(ICharacter& target) {

}
