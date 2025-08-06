/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:40:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 15:31:48 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::get_contact_info()
{
    getNonEmptyInput("Enter your first name...:", _firstName);
    getNonEmptyInput("Enter your last name...:", _lastName);
    getNonEmptyInput("Enter your nickname...:", _nickname);
    getNonEmptyInput("Enter your phone number...:", _phoneNumber);
    getNonEmptyInput("Enter your darkest secret...:", _darkestSecret);
}

std::string Contact::get_phoneNumber() {
    return(_phoneNumber);
}
std::string Contact::get_darkestSecret() {
    return(_darkestSecret);
}

void getNonEmptyInput(const std::string& message, std::string& target) {
    std::cout << message << std::endl;
    while (std::getline(std::cin, target)) {
        if (!target.empty())
            break;
        std::cout << "Input cannot be empty. Please try again." << std::endl;
        std::cout << message << std::endl;
    }
    if (std::cin.fail() || std::cin.eof()) {
        std::cout << "\nInput ended by EOF (Ctrl+D). Exiting." << std::endl;
    }
}

