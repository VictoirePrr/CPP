
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Create initial Form object
        Form formA("TopSecret", 1, 5);  // name, sign grade, execute grade


        // Attempt to sign the form with an invalid grade
        try {
            formA.beSigned(10);  // Assuming beSigned throws if grade too low
            std::cout << "formA signed successfully by grade 10" << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Signing formA failed: " << e.what() << std::endl;
        }

        // Create a copy of formA using the copy constructor
        Form formB(formA);
        std::cout << "Copied formB from formA: " << formB.getName()
                  << ", signed: " << (formB.isSigned() ? "yes" : "no") << std::endl;

        // Create another Form object and assign formA to it
        Form formC("Confidential", 3, 7);
        std::cout << "Created formC: " << formC.getName()
                  << ", signed: " << (formC.isSigned() ? "yes" : "no") << std::endl;

        formC = formA;  // Copy assignment operator (probably empty if const members)

        std::cout << "After assignment, formC: " << formC.getName()
                  << ", signed: " << (formC.isSigned() ? "yes" : "no") << std::endl;

        // You could add more tests here, like trying to sign with other grades,
        // printing grades, or checking formA's execution grade, etc.
    } catch (const std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


