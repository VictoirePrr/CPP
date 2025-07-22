/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:43 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/22 17:45:38 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

   int N = 8;
   std::string name = "David";

   Zombie *Horde = zombieHorde(N, name);
   delete(Horde); // --> check if the entire array is deleted or just the first pointer
   return(0);
}