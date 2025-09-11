#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern {


        public :

            class FormNameDoesntExist : public std::exception {
                public :
                    virtual const char* what() const throw() {
                return ("Form doesn't exist !");
                }
            };

            Intern();
            Intern(const Intern& other);
            Intern& operator=(const Intern& other);
            ~Intern();

            AForm *makeForm(std::string formName, std::string formTarget);

};

