/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:43 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/19 09:59:18 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

   int N = 8;
   std::string name = "David";

   Zombie *Horde = zombieHorde(N, name);
   for(int i = 0; i < N; i++) {
      Horde[i].announce();
   } 
   delete[] Horde; 
   return(0);
}