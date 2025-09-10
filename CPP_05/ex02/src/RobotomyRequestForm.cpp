#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target"){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
    _target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) 
    {
        _target = other._target;
         AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

void RobotomyRequestForm::executeAction() const {

    std::cout << "BZZZZZZZZ BZZZZZZZZZZZ BZZZZZZZZZZZ" << std::endl;

    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << _target << " robotomy failed" << std::endl;
}


std::string RobotomyRequestForm::getTarget() const {
    return(_target);
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f) {
    os << f.getName() << " ( " << f.getTarget() << " ) " << ", require grade " << f.getSignGrade() << " to sign and grade " << f.getExecGrade() 
    << " to execute it. It is currently : " << (f.isSigned() ? "Signed." : "Not signed.");
    return (os);
}