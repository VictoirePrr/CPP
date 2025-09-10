#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {

    private:

        const std::string _name;
        int _grade;
        Bureaucrat();

    public:

        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return ("Grade Too High !");
            }
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return ("Grade Too Low !");
            }
        };

        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const &form);

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP