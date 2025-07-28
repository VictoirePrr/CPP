/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:21:35 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 17:15:50 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    
    double denominator = denominatorCalc(a, b, c, point);
    double aD = ((b._y - c._y)*(point._x - c._x) + (c._x - b._x)*(point._y - c._y)) / denominator;
    double bD = ((c._y - a._y)*(point._x - c._x) + (a._x - c._x)*(point._y - c._y)) / denominator;
    double cD = 1 - a - b;

    return (aD >= 0) && (bD >= 0) && (cD >= 0);
}

