/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:03:44 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/07 12:32:16 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

Iter::Iter(const Iter &other) {
    (void)other;
}

Iter &Iter::operator=(const Iter &other) {
    
     if (this != &other) {
        (void)other;
    }
    return *this;
}

Iter::~Iter() {
    
}
