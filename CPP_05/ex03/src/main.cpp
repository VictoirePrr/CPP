/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:49:23 by victoire          #+#    #+#             */
/*   Updated: 2025/09/16 12:49:26 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Colors.hpp"
#include <iostream>

static void title(const std::string& txt, const char* color) {
    std::cout << color << "=== " << txt << " ===" << RESET << std::endl;
}

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("Low", 150);
        Intern someIntern;

        std::cout << boss << std::endl;
        std::cout << low << std::endl;

        // Shrubbery
        title("Shrubbery Creation", G);
        AForm* shrub = someIntern.makeForm("shrubbery creation", "Garden");
        if (shrub) {
            std::cout << *shrub << " target = " << shrub->getTarget() << std::endl;
            try { low.signForm(*shrub); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            try { boss.signForm(*shrub); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            try { boss.executeForm(*shrub); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            delete shrub;
        }

        // Robotomy
        title("Robotomy Request", C);
        AForm* robo = someIntern.makeForm("robotomy request", "Bender");
        if (robo) {
            std::cout << *robo << " target = " << robo->getTarget() << std::endl;
            boss.signForm(*robo);
            for (int i = 0; i < 3; ++i) {
                try { boss.executeForm(*robo); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            }
            delete robo;
        }

        // Pardon
        title("Presidential Pardon", M);
        AForm* pardon = someIntern.makeForm("presidential pardon", "Arthur Dent");
        if (pardon) {
            std::cout << *pardon << " target = " << pardon->getTarget() << std::endl;
            boss.signForm(*pardon);
            try { boss.executeForm(*pardon); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            delete pardon;
        }

        // Unknown
        title("Unknown Form", R);
        try {
            AForm* bad = someIntern.makeForm("unknown", "Nobody");
            if (bad) {
                std::cout << *bad << " target = " << bad->getTarget() << std::endl;
                delete bad;
            }
        } catch (std::exception& e) {
            std::cout << "Intern failed: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Uncaught exception: " << e.what() << std::endl;
    }
    return 0;
}
