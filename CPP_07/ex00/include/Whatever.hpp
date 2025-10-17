/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:00:38 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/17 14:53:26 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

        
        template <typename T> static void swap(T &a, T &b) {
            T temp = a;
            a = b;
            b = temp;
        }
        
        template <typename T> static T min(T &a, T &b) {
            if (a < b)
                return (a);
            return (b);
        }
        
        template <typename T> static T max(T &a, T &b) {
            if (a > b)
                return (a);
            return (b);
        }

#endif