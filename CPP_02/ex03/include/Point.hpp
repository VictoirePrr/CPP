/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:22:08 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 17:16:20 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
    
    private :

    Fixed _x = 0;
    Fixed _y = 0;

    public:


    Point(const Fixed& x, const Fixed& y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    Point(const float xf, const float yf);
    ~Point();

    Fixed getX( void ) const;
    void setX( int const raw );
    Fixed getY( void ) const;
    void setY( int const raw );

   static double denominatorCalc(const Point& a, const Point& b, const Point& c, const Point& point);
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif