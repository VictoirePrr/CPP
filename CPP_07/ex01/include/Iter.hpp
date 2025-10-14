/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:00:38 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/14 11:46:32 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

        
        template <typename T>
        void iter(T *array, const int &length, void (*func)(T&)) {
            if (length <= 0 || !array || !func)
                return ;
            for (int i = 0; i < length; i++)
                func(array[i]);
        }

        template <typename T>
        void iter(const T *array, const int &length, void (*func)(const T&)) {
            if (length <= 0 || !array || !func)
                return ;
            for (int i = 0; i < length; i++)
                func(array[i]);
        }
        

        template <typename T>
        void printArray(T &element) {
            std::cout << element << std::endl;
        }

#endif