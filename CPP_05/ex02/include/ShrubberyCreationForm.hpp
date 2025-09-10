#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

	private :

		std::string _target;
		ShrubberyCreationForm();

	public:

    	ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void executeAction() const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

#endif
