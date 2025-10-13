#include "Array.hpp"

int main(void) {
    std::cout << "===== INT ARRAY TEST =====" << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;

    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << "\n===== COPY TEST =====" << std::endl;
    Array<int> copyArray = intArray;
    copyArray[0] = 999;
    std::cout << "Original[0] = " << intArray[0] << " | Copy[0] = " << copyArray[0] << std::endl;

    std::cout << "\n===== STRING ARRAY TEST =====" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

    std::cout << "\n===== CONST ARRAY TEST =====" << std::endl;
    const Array<std::string> constArray = strArray;
    for (unsigned int i = 0; i < constArray.size(); i++)
        std::cout << "constArray[" << i << "] = " << constArray[i] << std::endl;

    std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;
    try {
        std::cout << intArray[10] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== EMPTY ARRAY TEST =====" << std::endl;
    Array<float> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}