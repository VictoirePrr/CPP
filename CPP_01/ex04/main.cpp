/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:16:40 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/24 16:36:52 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{

     if (argc != 4){
        std::cout << "Bad input." << std::endl;
        return (1);
    }

    for(int i = 1; i < 4; i++){
        if (!argv[i]){
            std::cout << "Bad input." << std::endl;
            return (1);
        }
    }

    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    Replace Test1(infile, s1, s2);
    return (0);
}