/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:53:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 13:59:51 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating ClapTrap called Iris:" << std::endl;
    ClapTrap ct1("Iris");

    std::cout << "\nCreating ScavTrap called Felix:" << std::endl;
    ScavTrap st1("Felix");

    std::cout << "\nTesting ClapTrap attack:" << std::endl;
    ct1.attack("Manon");

    std::cout << "\nTesting ScavTrap attack and guardGate:" << std::endl;
    st1.attack("Arthur");
    st1.guardGate();

    std::cout << "\nTesting takeDamage and beRepaired:" << std::endl;
    st1.takeDamage(30);
    st1.beRepaired(20);

    std::cout << "\nDemonstrating copy constructor and assignment operator with ScavTrap:" << std::endl;
    ScavTrap st2 = st1;
    st2.attack("copied target");

    ScavTrap st3;
    st3 = st2;
    st3.guardGate();

    std::cout << "\nDestroying objects now..." << std::endl;

    return 0;
}

