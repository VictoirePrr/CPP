/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:39:54 by victoire          #+#    #+#             */
/*   Updated: 2025/09/23 13:54:38 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc > 2 || argc == 1) {
        std::cout << "ERROR : enter one argument." << std::endl;
        return (0);
    }
    std::string argStr(argv[1]);
    ScalarConverter::convert(argStr);
    return (0);
}