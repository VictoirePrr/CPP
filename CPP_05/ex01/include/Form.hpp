/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:54:01 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 11:29:00 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {

    private :

        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
        Form();

    public :

	    class GradeTooHighException : public std::exception {
				public:
					const char *what() const throw();
			};
			
		class GradeTooLowException : public std::exception {
				public:
					const char *what() const throw();
			};

        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        Form(const std::string name, const int signGrade, const int execGrade);


        const std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool beSigned(Bureaucrat const &b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif 
