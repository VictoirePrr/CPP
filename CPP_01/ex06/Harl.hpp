/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:29:31 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/25 11:14:05 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <iostream>

class HarlFilter {
    
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public :
        HarlFilter();
        ~HarlFilter();
        void complain( std::string level );
    
};

#endif
