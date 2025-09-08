#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private :

		std::string _target;

	public:

		PresidentialPardonForm();
    	PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);
		bool beSigned(Bureaucrat *b) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f);

#endif
