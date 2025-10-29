/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:15:00 by victoire          #+#    #+#             */
/*   Updated: 2025/10/29 15:39:06 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << BB << "=== Basic test ===" << RESET << std::endl;
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
        std::cerr << BR << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BB << "=== Exception: Span full ===" << RESET << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // should throw
    }
    catch (std::exception &e) {
        std::cerr << BR << "Caught: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BB << "=== Exception: Not enough numbers ===" << RESET << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // should throw
    }
    catch (std::exception &e) {
        std::cerr << BR << "Caught: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BB << "=== Range insertion test ===" << RESET << std::endl;
    try {
        Span bigSpan(10000);
        std::vector<int> vec;

        for (int i = 0; i < 10000; i++)
            vec.push_back(std::rand() % 100000);

        bigSpan.addRange(vec.begin(), vec.end());

        std::cout << BG << "Range successfully added!" << RESET << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << BR << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BB << "=== Tiny span ===" << RESET << std::endl;
    try {
        Span sp(2);
        sp.addNumber(5);
        sp.addNumber(6);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << BR << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}

