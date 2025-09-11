#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat vic;

    std::cout << RED << "==== Trying to create an object with grade too low ==== " << RESET << std::endl;
    try {
        vic = Bureaucrat("vicperri", 180);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << RED << "==== Trying to create an object with grade in range ==== " << RESET << std::endl;
    try {
        vic = Bureaucrat("vicperri", 75);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << vic << std::endl;

    std::cout << RED << "==== Decrementing grade until it is too low ==== " << RESET << std::endl;
    for (int i = 0; i < 76; i++) {
        try {
            vic.decrementGrade();
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << vic << std::endl;

    std::cout << RED << "==== Incrementing grade until it is too high ==== " << RESET << std::endl;
    for (int i = 0; i < 150; i++) {
        try {
            vic.incrementGrade();
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << vic << std::endl;
    
    return (0);
}
