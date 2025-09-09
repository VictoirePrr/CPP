#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {

	private :

		std::string _target;

	public:

		RobotomyRequestForm();
    	RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		void executeAction() const ;
};
 
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f);

#endif
