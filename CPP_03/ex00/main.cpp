/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/25 09:27:59 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"  
 
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

int main() {
    std::cout << RED << "=== ClapTrap Test Begins ===" << RESET << std::endl;

    ClapTrap manon("Manon");

    std::cout << RED << "\n-- Action Phase --" << RESET << std::endl;
    manon.attack("zombie");
    manon.takeDamage(3);
    manon.beRepaired(5);
    manon.attack("vampire");
    manon.takeDamage(15);
    manon.beRepaired(5);
    manon.attack("bear");

    std::cout << RED << "\n=== ClapTrap Test Ends ===" << RESET << std::endl;
    return 0;
}
