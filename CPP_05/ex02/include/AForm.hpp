#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {

    private :

        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public :

        class FormNotSignedException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Form is not signed !");
            }
    };

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

        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        AForm(const std::string name, const int signGrade, const int execGrade);

        const std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        bool beSigned(Bureaucrat const &b);
        bool execute(Bureaucrat const &executor) const;

        virtual void executeAction() const = 0; 

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif 
