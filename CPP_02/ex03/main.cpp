/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:33:14 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/28 17:10:34 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"
#include "include/Point.hpp"

int main ()
{
    Point A{0, 0};
    Point B{5, 0};
    Point C{0, 5};

    Point P1{1, 1};
    Point P2{6, 6};

    std::cout << "P1 est " << (bsp(A, B, C, P1) ? "dans" : "hors") << " le triangle" <<  std::endl;
    std::cout << "P2 est " << (bsp(A, B, C, P2) ? "dans" : "hors") << " le triangle" <<  std::endl;

    return (0);
}