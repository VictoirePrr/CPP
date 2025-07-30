/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 13:29:22 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"  
 

int main() {
    ClapTrap ct1("Iris");
    ClapTrap ct2("Felix");

    std::cout << "\n--- Test attack ---" << std::endl;
    ct1.attack("ninja Arthur");

    std::cout << "\n--- Test takeDamage ---" << std::endl;
    ct2.takeDamage(3);

    std::cout << "\n--- Test repair ---" << std::endl;
    ct2.beRepaired(5);

    std::cout << "\n--- Test attack with no hit points ---" << std::endl;
    ct2.takeDamage(20); 
    ct2.attack("ninja Arthur");
    ct2.beRepaired(5);

    std::cout << "\n--- Test attack with no energy points ---" << std::endl;
    ClapTrap ct5("Louis");
    for (int i = 0; i < 10; ++i) {
        ct5.attack("ninja Arthur");
    }
    ct5.attack("ninja Arthur");
    ct5.beRepaired(3);

    return 0;
}
