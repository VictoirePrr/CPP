/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:11:46 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 11:26:53 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
				public:
					const char *what() const throw();
			};

		class GradeTooLowException : public std::exception {
				public:
					const char *what() const throw();
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

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

