#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {

    private :

        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public :

        class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Grade Too High !");
            }
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Grade Too Low !");
            }
    };

        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();


        const std::string getName() const;
        bool getSigned() const;
        const int getSignGrade() const;
        const int getExecGrade() const;
        void beSigned(Bureaucrat &b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif 
