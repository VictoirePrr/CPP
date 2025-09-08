#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) {

}

bool RobotomyRequestForm::beSigned(Bureaucrat *b)
{

}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f) {
    os << f.getName() << ", RobotomyRequestForm require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. The RobotomyRequestForm is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}