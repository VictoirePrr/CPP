/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:58:50 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/12 14:05:40 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void PhoneBook::get_contact_info(std::string argv)
{
    if(argv[i] == "ADD")
    {
        std::cout >> Enter you first name...:<< std::endl;
        std::cin >> info[0][0];
        std::cout >> Enter you last name...:<< std::endl;
        std::cout >> Enter you nickname...:<< std::endl;
        std::cout >> Enter you phone number...:<< std::endl;
        std::cout >> Enter you darkest secret...:<< std::endl;
    }
}

int main(int argc, char **argv)
{
    //put it in a while loop so that it keeps asking the user info... 
    PhoneBook::get_contact_info(argv[i]);
    PhoneBook::show_contact_info();
    //  Contact::show_phonebook(PhoneBook& contact);
}