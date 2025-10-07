/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:03:44 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/07 12:27:39 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

Whatever::Whatever(const Whatever &other) {
    (void)other;
}

Whatever &Whatever::operator=(const Whatever &other) {
    
     if (this != &other) {
        (void)other;
    }
    return *this;
}

Whatever::~Whatever() {
    
}

// template <typename T>
// void Whatever::swap(T a, T b) {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// template <typename T>
// T Whatever::min(T a, T b) {
//     if (a < b)
//         return (a);
//     return (b);
// }

// template <typename T>
// T Whatever::max(T a, T b) {
//     if (a > b)
//         return (a);
//     return (b);
// }