/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/09/02 11:02:49 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

    private :

        Brain *_brain;

    public :

        Cat();
        Cat(const Cat &copy);
        Cat& operator=(const Cat &copy);
        ~Cat();

        void makeSound() const ;
};

#endif