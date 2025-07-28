/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:31:57 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 15:30:00 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private :
    
        int _value;
        static const int _factor = 8;
    
    public :
    
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

        friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
        
        Fixed operator>(const Fixed& other) const;
        Fixed operator<(const Fixed& other) const;
        Fixed operator>=(const Fixed& other) const;
        Fixed operator==(const Fixed& other) const;
        Fixed operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed operator++(int);
        Fixed operator--(int);
        Fixed& operator++();
        Fixed& operator--();

        static Fixed min(Fixed& f0, Fixed& f1);
        static Fixed min(const Fixed& f0, const Fixed& f1);
        static Fixed max(Fixed& f0, Fixed& f1);
        static Fixed max(const Fixed& f0, const Fixed& f1);
        
    
};


#endif