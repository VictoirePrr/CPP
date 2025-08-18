/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:32:59 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/18 15:27:03 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    _value = 0;
}

Fixed::Fixed(const int value) {
    _value = value * (1 << _factor);
}

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _factor));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& other) {
    _value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other._value;
    return (*this);
}

int Fixed::getRawBits(void) const {
    return (_value);
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_value) / (1 << _factor));
}

int Fixed::toInt(void) const {
    return (_value >> _factor);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& other) const {
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const {
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const {
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed temp;
    temp.setRawBits(_value + other._value);
    return (temp);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed temp;
    temp.setRawBits(_value - other._value);
    return (temp);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed temp;
    temp.setRawBits((_value * other._value) >> _factor);
    return (temp);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed temp;
    temp.setRawBits((_value << _factor) / other._value);
    return (temp);
}

Fixed& Fixed::operator++() {
    ++_value;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_value;
    return (temp);
}

Fixed& Fixed::operator--() {
    --_value;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_value;
    return (temp);
}

Fixed& Fixed::min(Fixed& f0, Fixed& f1) {
    if (f0 < f1)
        return (f0);
    return (f1);
}

const Fixed& Fixed::min(const Fixed& f0, const Fixed& f1) {
    if (f0 < f1)
        return (f0);
    return (f1);
}

Fixed& Fixed::max(Fixed& f0, Fixed& f1) {
    if (f0 > f1)
        return (f0);
    return (f1);
}

const Fixed& Fixed::max(const Fixed& f0, const Fixed& f1) {
    if (f0 > f1)
        return (f0);
    return (f1);
}
