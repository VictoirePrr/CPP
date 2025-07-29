/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:32:59 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/29 15:20:30 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    _value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    _value = value * (1 << _factor);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    _value = roundf((value * (1 << _factor)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
     std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
         this->_value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const {
    return (_value);
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return ((float)(_value) / (1 << _factor));
}

int Fixed::toInt( void ) const {
    return ((_value) / (1 << _factor));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    float value = (float)(f._value) / (1 << f._factor);
    os << value;
    return (os);
}
