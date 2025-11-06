#include "RPN.hpp"

int main(int argc, char **argv) {

    if(argc != 2) {
        std::cout << "ERROR: must take one argument." << std::endl;
        return 1;
    }

    RPN start;
    std::string expr = argv[1];

    try {
            start.parseExpr(expr);
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    start.polishOp(expr);
    return 0;
}
