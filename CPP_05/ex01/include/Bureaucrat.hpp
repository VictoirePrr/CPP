
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define RED   "\033[31m"
#define RESET "\033[0m"

class Bureaucrat {
    
    private :

        const std::string _name;
        int _grade;

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

        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
