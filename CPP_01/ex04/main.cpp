/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:16:40 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/23 14:24:23 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.h"

int main(){
    std::string s1 = "segfault";
    std::string s2 = "tié 1 monstre";
    std::string input = "input.txt";
    // Replace Test(input, s1, s2);
    
    std::string s3 = "a";
    std::string s4 = "  ";
    Replace Test1(input, s3, s4);
    
    std::string nofile = "";
    // Replace Test2(nofile, s3, s4);
}