/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:22:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 17:15:35 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const Fixed& x, const Fixed& y) {
}

Point::Point(const Point& other){
    this->_x = other.getX();
    this->_y = other.getY();
}

Point& Point::operator=(const Point& other) {
    if (this != &other)
    {
         this->_x = other.getX();
         this->_y = other.getY();
    }
    return (*this);
}

Point::Point(const float xf, const float yf) {
    _x = xf;
    _y = yf;
}

Point::~Point() {
}

Fixed Point::getX( void ) const {
    return (_x);
}

Fixed Point::getY( void ) const {
    return (_y);
}

void Point::setX( int const raw ){
    _x = raw;
}

void Point::setY( int const raw ){
    _y = raw;
}

double Point::denominatorCalc(const Point& a, const Point& b, const Point& c, const Point& point)
{
    double denominator = (b._y - c._y)*(a._x - c._x) + (c._x - b._x)*(a._y - c._y);
    if (denominator == 0) {
        // Triangle dégénéré (aire nulle)
        return false;
    }
    return (denominator)
}