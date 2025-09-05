#ifndef FORM_HPP
#define FORM_HPP

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
        Form(const std::string name, const int signGrade, const int execGrade);


        const std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool beSigned(const int signature);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif 
