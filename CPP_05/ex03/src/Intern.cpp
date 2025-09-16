#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

Intern::~Intern() {
}


AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    int i = 0;
    
    enum lvl { President, Robotomy, Shrubbery };

    std::string compare[] = {
        "presidential pardon", 
        "robotomy request", 
        "shrubbery creation", 
    };

    while(i < 3)
    {
        if(compare[i] == formName)
            break;
        i++;
    }
    
    switch (i) {
        case President : {
                std::cout << "Intern creates Presidential Pardon Form"  << std::endl;
                return(new PresidentialPardonForm(formTarget));
            }

        case Robotomy: {
            std::cout << "Intern creates Robotomy Request Form"  << std::endl;
            return(new RobotomyRequestForm(formTarget));
        }

        case Shrubbery: {
            std::cout << "Intern creates Shrubbery Creation Form"  << std::endl;
            return(new ShrubberyCreationForm(formTarget));
        }

        default:
            throw FormNameDoesntExist();
            break;
    }
}
