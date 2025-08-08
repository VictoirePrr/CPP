/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:31:10 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/25 11:17:43 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

HarlFilter::HarlFilter(){
}

HarlFilter::~HarlFilter(){
}

void HarlFilter::debug( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7 XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
   std::cout << std::endl;
}

void HarlFilter::info( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}
    
void HarlFilter::warning( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}
    
void HarlFilter::error( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}


void HarlFilter::complain( std::string level ){
    
    int i = 0;
    void (HarlFilter::*Harlptr[])() = {
        &HarlFilter::debug,
        &HarlFilter::info,
        &HarlFilter::warning,
        &HarlFilter::error
    };
    
    enum lvl { DEBUG, INFO, WARNING, ERROR };

    std::string compare[] = {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };

    while(i < 4)
    {
        if(compare[i] == level)
            break;
        i++;
    }
    
    switch (i) {
        case DEBUG : (this->*Harlptr[0])(); 
        case INFO: (this->*Harlptr[1])(); 
        case WARNING: (this->*Harlptr[2])(); 
        case ERROR: (this->*Harlptr[3])(); 
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}


