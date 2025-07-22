/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 16:48:12 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
        Zombie **horde = new Zombie*[N];
        for(int i = 0; i < N; i++)
        {
            horde[i] = new Zombie(name);
            horde[i]->announce();
        }  
    return (*horde);
}