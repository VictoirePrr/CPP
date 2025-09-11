/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:12 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 13:38:03 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Colors.hpp"

#include <iostream>
#include <vector>
#include <string>


// Fallback if your project doesn't include these color macros here.
// (If you already have them, these are ignored.)


static void title(const std::string& s) {
    std::cout << R << "=== " << s << " ===" << RESET << std::endl;
}

// Small helper to sign & execute while catching + printing exceptions cleanly.
static void signAndExec(Bureaucrat& b, AForm& f) {
    try {
        std::cout << b << " tries to sign -> " << f.getName() << std::endl;
        b.signForm(f);
    } catch (std::exception& e) {
        std::cout << "Signing failed: " << e.what() << std::endl;
    }
    try {
        std::cout << b << " tries to execute -> " << f.getName() << std::endl;
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Execution failed: " << e.what() << std::endl;
    }
}

int main() {
    try {
        title("Setup bureaucrats");
        Bureaucrat ceo("CEO", 1);
        Bureaucrat mid("Mid", 70);
        Bureaucrat low("Low", 145);

        std::cout << ceo << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        title("Create intern");
        Intern someRandomIntern;

        // Adjust the exact strings to match your Intern::makeForm mapping:
        // Common mapping in 42 subjects:
        //  - "shrubbery creation"
        //  - "robotomy request"
        //  - "presidential pardon"
        // If your project uses other spellings, tweak below.
        std::vector<AForm*> forms;
        try {
            title("Intern makes shrubbery creation");
            forms.push_back(someRandomIntern.makeForm("shrubbery creation", "home"));
            std::cout << *forms.back() << std::endl;
        } catch (std::exception& e) {
            std::cout << "Intern failed to make shrubbery: " << e.what() << std::endl;
        }

        try {
            title("Intern makes robotomy request");
            forms.push_back(someRandomIntern.makeForm("robotomy request", "Bender"));
            std::cout << *forms.back() << std::endl;
        } catch (std::exception& e) {
            std::cout << "Intern failed to make robotomy: " << e.what() << std::endl;
        }

        try {
            title("Intern makes presidential pardon");
            forms.push_back(someRandomIntern.makeForm("presidential pardon", "Marvin"));
            std::cout << *forms.back() << std::endl;
        } catch (std::exception& e) {
            std::cout << "Intern failed to make pardon: " << e.what() << std::endl;
        }

        // Unknown form (should error)
        try {
            title("Intern tries unknown form");
            AForm* bad = someRandomIntern.makeForm("unknown paper", "TargetX");
            // If your makeForm returns nullptr on failure instead of throwing:
            if (!bad) std::cout << "Intern returned nullptr for unknown form (expected)\n";
            else {
                std::cout << *bad << std::endl;
                delete bad;
            }
        } catch (std::exception& e) {
            std::cout << "Unknown form correctly failed: " << e.what() << std::endl;
        }

        // Now, if any of the expected forms exist, test behaviors.
        // Find pointers by name (defensive in case creation failed).
        AForm* shrub = NULL;
        AForm* robo  = NULL;
        AForm* pardon= NULL;
        for (size_t i = 0; i < forms.size(); ++i) {
            if (!forms[i]) continue;
            if (forms[i]->getName().find("Shrubbery") != std::string::npos
             || forms[i]->getName().find("shrubbery") != std::string::npos)
                shrub = forms[i];
            else if (forms[i]->getName().find("Robotomy") != std::string::npos
                  || forms[i]->getName().find("robotomy") != std::string::npos)
                robo = forms[i];
            else if (forms[i]->getName().find("Presidential") != std::string::npos
                  || forms[i]->getName().find("presidential") != std::string::npos)
                pardon = forms[i];
        }

        // 1) Try executing unsigned form (should throw)
        if (shrub) {
            title("Execute unsigned shrubbery (should fail)");
            try {
                ceo.executeForm(*shrub);
            } catch (std::exception& e) {
                std::cout << "Expected failure: " << e.what() << std::endl;
            }
        }

        // 2) Low grade tries to sign/exec shrubbery (sign should fail if sign grade < 145)
        if (shrub) {
            title("Low tries shrubbery");
            signAndExec(low, *shrub);
        }

        // 3) Mid signs shrubbery, then Low tries to exec (exec likely fails), then CEO executes
        if (shrub) {
            title("Mid signs shrubbery; Low executes; CEO executes");
            try { mid.signForm(*shrub); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            try { low.executeForm(*shrub); } catch (std::exception& e) { std::cout << "Low exec failed: " << e.what() << std::endl; }
            try { ceo.executeForm(*shrub); } catch (std::exception& e) { std::cout << "CEO exec failed: " << e.what() << std::endl; }
        }

        // 4) Robotomy randomness: sign with high enough and execute multiple times
        if (robo) {
            title("Robotomy randomness (run 5 times)");
            try { ceo.signForm(*robo); } catch (std::exception& e) { std::cout << e.what() << std::endl; }
            for (int i = 0; i < 5; ++i) {
                try {
                    ceo.executeForm(*robo);
                } catch (std::exception& e) {
                    std::cout << "Robotomy exec failed: " << e.what() << std::endl;
                    break;
                }
            }
        }

        // 5) Presidential pardon: mid signs (might fail), CEO executes
        if (pardon) {
            title("Presidential pardon flow");
            try { mid.signForm(*pardon); } catch (std::exception& e) { std::cout << "Mid sign failed: " << e.what() << std::endl; }
            try { ceo.signForm(*pardon); } catch (std::exception& e) { std::cout << "CEO sign (if needed): " << e.what() << std::endl; }
            try { ceo.executeForm(*pardon); } catch (std::exception& e) { std::cout << "CEO exec failed: " << e.what() << std::endl; }
        }

        // Clean up
        title("Cleanup");
        for (size_t i = 0; i < forms.size(); ++i) {
            delete forms[i];
        }
    }
    catch (std::exception& e) {
        std::cerr << BR "Uncaught exception in main: " RESET << e.what() << std::endl;
    }
    return 0;
}
