/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:30:55 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/24 16:26:09 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Bad input." << std::endl;
        return(1);
    }
    
    Harl level;
    level.complain(argv[1]);
    return (0);
}