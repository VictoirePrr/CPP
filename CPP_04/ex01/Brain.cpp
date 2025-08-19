/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:16:52 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/19 15:21:33 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain &copy) {
    if(this != &copy)
        //
    return(*this);
}

Brain::Brain(const Brain &copy) {
    //
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}