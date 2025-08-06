/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:43 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 11:08:14 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

   int N = 8;
   std::string name = "David";

   Zombie *Horde = zombieHorde(N, name);
   delete[] Horde; 
   return(0);
}