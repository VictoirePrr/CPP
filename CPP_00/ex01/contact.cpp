/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:40:22 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 16:38:51 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::get_contact_info()
{
    std::cout << "Enter your first name...:" << std::endl;
    std::getline(std::cin, _firstName);
    std::cout << "Enter your last name...:" << std::endl;  
    std::getline(std::cin, _lastName);
    std::cout << "Enter your nickname...:" << std::endl;
    std::getline(std::cin, _nickname);
    std::cout << "Enter your phone number...:" << std::endl;
    std::getline(std::cin, _phoneNumber);
    std::cout << "Enter your darkest secret...:" << std::endl;
    std::getline(std::cin, _darkestSecret);
}
