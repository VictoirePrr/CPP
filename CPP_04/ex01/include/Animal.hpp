/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/19 14:13:11 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RED   "\033[31m"
#define RESET "\033[0m"


class Animal {
  
    protected :

        std::string type;

    public :

        Animal();
        Animal(const Animal &copy);
        Animal& operator=(const Animal &copy);
        virtual ~Animal();

        virtual void makeSound() const;
        virtual std::string getType() const;
};

#endif