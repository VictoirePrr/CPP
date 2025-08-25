/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/07 14:34:55 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>


#define RED   "\033[31m"
#define RESET "\033[0m"

class WrongAnimal {
  
    protected :

        std::string type;

    public :

        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal& operator=(const WrongAnimal &copy);
        virtual ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
};

#endif