/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:15:00 by victoire          #+#    #+#             */
/*   Updated: 2025/10/28 14:49:28 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << BLUE << "=== Basic test ===" << RESET << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "=== Exception: Span full ===" << RESET << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // should throw
    }
    catch (std::exception &e) {
        std::cerr << RED << "Caught: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "=== Exception: Not enough numbers ===" << RESET << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // should throw
    }
    catch (std::exception &e) {
        std::cerr << RED << "Caught: " << e.what() << RESET << std::endl;
    }

    // std::cout << std::endl << BLUE << "=== Range insertion test ===" << RESET << std::endl;
    // try {
    //     Span bigSpan(10000);
    //     std::vector<int> vec;

    //     for (int i = 0; i < 10000; i++)
    //         vec.push_back(std::rand() % 100000);

    //     bigSpan.addRange(vec.begin(), vec.end());

    //     std::cout << GREEN << "Range successfully added!" << RESET << std::endl;
    //     std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    //     std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    // }

    std::cout << std::endl << BLUE << "=== Tiny span ===" << RESET << std::endl;
    try {
        Span sp(2);
        sp.addNumber(5);
        sp.addNumber(6);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << YELLOW << "✨ All tests done! ✨" << RESET << std::endl;
    return 0;
}

