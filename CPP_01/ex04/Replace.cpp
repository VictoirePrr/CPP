/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:21:32 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/18 15:08:03 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string& infile, std::string s1, std::string s2){

    std::ifstream inputFile(infile.c_str());
    
    if (!inputFile.is_open()) {
        std::cout << "Failed to open the input file." << std::endl;
        return;
    }
    std::string outputFilename = infile + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cout << "Failed to open the output file." << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string newline;
        std::size_t pos = 0;
        while (true) {
            if (s1.empty())
            {
                 newline += line.substr(pos);
                break;
            }
            std::size_t found = line.find(s1, pos);
            if (found != std::string::npos) {
                newline += line.substr(pos, found - pos);
                newline += s2;
                pos = found + s1.length();
            }
            else {
                newline += line.substr(pos);
                break;
            }
        }
        outputFile << newline << "\n";
    }
    inputFile.close();
    outputFile.close();
     
}


Replace::~Replace(){
}

