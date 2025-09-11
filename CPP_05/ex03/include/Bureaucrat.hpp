/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:14:08 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 12:14:10 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
