/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:29:31 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/24 16:14:43 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
    
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public :
        Harl();
        ~Harl();
        void complain( std::string level );
    
};

#endif
