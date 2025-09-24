/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:39:54 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 15:33:11 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc > 2 || argc == 1) {
        std::cout << "ERROR : enter one argument." << std::endl;
        return (0);
    }
    std::string argStr(argv[1]);
    try {
        ScalarConverter::convert(argStr);
    }
    catch (std::exception& e) {
         std::cout << e.what() << std::endl; 
    }
    return (0);
}