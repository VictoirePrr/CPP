/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:00:38 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/07 15:23:59 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

class Iter {

    private :
    
        Iter();

    public :
    
        Iter(const Iter &other);
        Iter &operator=(const Iter &other);
        ~Iter();
        
        template <typename A, typename L, typename F>
        static void iter(A *array, const L &lenght, F func) {
            for (L i = 0; i < lenght; i++)
                func(array[i]);
        }

        // template <typename A, typename L, typename F>
        // static void iter(A &array, L &lenght, const F &func) {
        //      for (L i = 0; i < lenght; i++)
        //         func(array[i]);
        // }
        
};

template <typename T>
void printArray(T &array) {
    std::cout << array << std::endl;
}

#endif