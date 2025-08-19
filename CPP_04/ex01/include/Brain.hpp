/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:35 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/19 15:22:00 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    
    private :

        std::string ideas[100];

    public :
    
        Brain();
        Brain& operator=(const Brain &copy);
        Brain(const Brain &copy);
        ~Brain();
};

#endif