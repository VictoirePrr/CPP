
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);       
        Form taxForm("TaxForm", 45, 60);   
        std::cout << john << std::endl;    

        std::cout << taxForm << std::endl; 

        john.signForm(taxForm);           
        std::cout << taxForm << std::endl; 

        Bureaucrat alice("Alice", 40);    
        alice.signForm(taxForm); 
        std::cout << taxForm << std::endl;

        Form badForm("BadForm", 0, 170); 
    }
    catch (std::exception& e) {
        std::cerr << "Exception from BadForm : " << e.what() << std::endl;
    }
    return 0;
}


