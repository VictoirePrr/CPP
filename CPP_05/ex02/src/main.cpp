#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Alice", 1);
        Bureaucrat intern("Bob", 150);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- Intern tries to sign forms ---" << std::endl;
        intern.signForm(shrub);
        intern.signForm(robot);
        intern.signForm(pardon);

        std::cout << "\n--- Boss signs all forms ---" << std::endl;
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        std::cout << "\n--- Intern tries to execute forms ---" << std::endl;
        intern.executeForm(shrub);
        intern.executeForm(robot);
        intern.executeForm(pardon);

        std::cout << "\n--- Boss executes forms ---" << std::endl;
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}



