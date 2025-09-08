#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private :

		std::string _target;

	public:

		ShrubberyCreationForm();
    	ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		bool beSigned(Bureaucrat *b) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif
