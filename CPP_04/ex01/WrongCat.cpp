/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:01 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 11:31:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() {
        std::cout << "WrongCat constructor called." << std::endl;
}
 
WrongCat::WrongCat(const WrongCat &copy) {
        type = copy.type;
}
    
WrongCat& WrongCat::operator=(const WrongCat &copy) {
        if (this != &copy)
            type = copy.type;
        return(*this);
}
    
WrongCat::~WrongCat() {    
        std::cout << "WrongCat destructor called." << std::endl;
}