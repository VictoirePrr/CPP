/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:31:10 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/24 16:25:19 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7 XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
    
void Harl::warning( void ){
        std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
    
void Harl::error( void ){
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level ){
    
    int i = 0;
    void (Harl::*Harlptr[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string compare[] = {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };

    while(i < 4)
    {
        if(compare[i] == level)
        {
            (this->*Harlptr[i])();
            break;
        }
        i++;
    }
    
    if(compare[i] != level)
        std::cout << "Comment not found." << std::endl;
}

// void Harl::complain( std::string level ){
    
//     int result;
//     enum lvl { DEBUG, INFO, WARNING, ERROR };
    
//      switch (lvl) {
//         case DEBUG :  result = level.compare("DEBUG"); 
//             break;
//         case INFO:  result = level.compare("DEBUG");
//             break;
//         case WARNING:  result = level.compare("DEBUG");
//             break;
//         case ERROR:  result = level.compare("DEBUG");
//             break;
//     };
    
//     switch (result) {
//         case DEBUG : debug(); 
//             break;
//         case INFO: info(); 
//             break;
//         case WARNING: warning(); 
//             break;
//         case ERROR: error(); 
//             break;
//     }
// }

