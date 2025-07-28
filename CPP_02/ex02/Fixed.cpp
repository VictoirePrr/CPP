/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:32:59 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 15:50:41 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    _value = 0;
}

Fixed::Fixed(const int value){
    _value = value * (1 << _factor);
}

Fixed::Fixed(const float value){
    _value = roundf((value * (1 << _factor)));
}

Fixed::~Fixed(){

}

Fixed::Fixed(const Fixed& other){
    this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
         this->_value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const {
    return (_value);
}

void Fixed::setRawBits( int const raw ){
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(_value) / (1 << _factor);
}

int Fixed::toInt( void ) const {
    return ((_value) / (1 << _factor));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    float value = static_cast<float>(f._value) / (1 << f._factor);
    os << value;
    return os;
}

Fixed Fixed::operator>(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value > other.getRawBits());
    return (temp);
}

Fixed Fixed::operator<(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value < other.getRawBits());
    return (temp);
 }

Fixed Fixed::operator>=(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value >= other.getRawBits());
    return (temp);
 }

Fixed Fixed::operator==(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value == other.getRawBits());
    return (temp);
 }
 
Fixed Fixed::operator!=(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value != other.getRawBits());
    return (temp);
 }
 
Fixed Fixed::operator+(const Fixed& other)  const {
   Fixed temp;
    
    temp.setRawBits(_value + other.getRawBits());
    return (temp);
 }

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value - other.getRawBits());
    return (temp);
 }

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value * other.getRawBits() >> _factor);
    return (temp);
 }
 
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed temp;
    
    temp.setRawBits(_value / other.getRawBits() << _factor);
    return (temp);
}

Fixed Fixed::operator++(int)  {
    Fixed temp = *this;
    this->_value++;
    return (temp);
}

Fixed Fixed::operator--(int)  {
    Fixed temp = *this;
    this->_value--;
    return (temp);
}

Fixed& Fixed::operator++() {
    ++_value;
    return (*this);
}

Fixed& Fixed::operator--() {
    --_value;
    return (*this);
}

Fixed Fixed::min(Fixed& f0, Fixed& f1) {
    if (f0.getRawBits() < f1.getRawBits())
        return (f0);
    return (f1);
}

Fixed Fixed::min(const Fixed& f0, const Fixed& f1) {
    if (f0.getRawBits() < f1.getRawBits())
        return (f0);
    return (f1);
}

Fixed Fixed::max(Fixed& f0, Fixed& f1) {
    if (f0.getRawBits() < f1.getRawBits())
        return (f1);
    return (f0);
}
 
Fixed Fixed::max(const Fixed& f0, const Fixed& f1) {
    if (f0.getRawBits() < f1.getRawBits())
        return (f1);
    return (f0);
}
