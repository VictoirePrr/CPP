/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:58:00 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 11:15:21 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
        Zombie *horde = new Zombie[N];
        for(int i = 0; i < N; i++)
        {
            horde[i].Setname(name);
            horde[i].announce();
        }  
    return (horde);
}