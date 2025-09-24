/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:12 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 11:07:16 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

int main() {
    srand(time(NULL));
    try {
        std::cout << BM << "---- Creating Bureaucrats ----" << RESET << std::endl;
        Bureaucrat alice("Alice", 1);   // top grade
        Bureaucrat bob("Bob", 50);      // medium grade
        Bureaucrat tom("Tom", 150);     // lowest grade

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << tom << std::endl;

        std::cout << BM << "\n---- Creating Forms ----" << RESET << std::endl;
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robo("BMarvin");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << BM << "\n---- Testing signing ----" << RESET << std::endl;
        std::cout << R; tom.signForm(shrub);   // should fail
        std::cout << G; bob.signForm(shrub); // should succeed
        std::cout << G; alice.signForm(robo);// should succeed
        std::cout << G; alice.signForm(pardon);// should succeed
        std::cout << RESET;

        std::cout << BM << "\n---- Executing forms ----" << RESET << std::endl;
        std::cout << R; tom.executeForm(shrub);    // should fail
        std::cout << G; bob.executeForm(shrub);  // should succeed, create file
        std::cout << R; bob.executeForm(robo);     // grade too low
        std::cout << G; alice.executeForm(robo); // should succeed, 50% chance
        std::cout << G; alice.executeForm(pardon);// should succeed
        std::cout << RESET;

        std::cout << BM << "\n---- Checking Forms ----" << RESET << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;


        std::cout << BM << "\n---- Polymorphism test ----" << RESET << std::endl;
        AForm* forms[3] = {
            new ShrubberyCreationForm("Garden"),
            new RobotomyRequestForm("Bender"),
            new PresidentialPardonForm("Ford Prefect")
        };

        for (int i = 0; i < 3; i++) {
            std::cout << G << "\n[Form " << i+1 << "]" << RESET << std::endl;
            alice.signForm(*forms[i]);
            alice.executeForm(*forms[i]);
            delete forms[i];
        }

    } catch (std::exception& e) {
        std::cerr << R << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}
