/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 14:39:09 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : virtual protected WrongAnimal {
  
    protected :

    std::string type;

    public :

    WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat& operator=(const WrongCat &copy);
    virtual ~WrongCat();

};

#endif