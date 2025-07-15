/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:26:05 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/15 11:10:15 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char* argv[]) {
    if(argc > 1)
    {
        for(int i = 1; argv[i]; i++)
        {
            for(int j = 0; argv[i][j]; j++)
            {
                if (isalpha(argv[i][j]) && islower(argv[i][j]))
                {
                    char c = toupper(argv[i][j]);
                    std::cout << c;
                }
                else
                    std::cout << argv[i][j];
            }
             std::cout << " ";
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
     std::cout << std::endl;
    return 0;
}