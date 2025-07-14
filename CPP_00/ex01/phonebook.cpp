/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:58:50 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/12 17:01:25 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void print_text(const std::string& text) 
{
    if (text.length() > 10) 
        std::cout << text.substr(0, 9) << "." << std::endl;
    else 
        std::cout << text << std::endl;
}

void PhoneBook::get_contact_info(int num)
{
    print_text("Enter your first name...:");
    std::cin >> info[num][0];
    print_text("Enter your last name...:");  
    std::cin >> info[num][1];
    print_text("Enter your nickname...:");
    std::cin >> info[num][2];
    print_text("Enter your phone number...:");
    std::cin >> info[num][3];
    print_text("Enter your darkest secret...:");
    std::cin >> info[num][4];
}

void PhoneBook::show_contacts_info()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " | ";
        for (int j = 0; j < 5; j++)
        {
            std::cout << info[i][j];
            if (j != 4)
              std::cout << " | ";
        }
        std::cout << std::endl;
        if (info[i + 1][0].empty())
               i = 8; 
    }
}

void PhoneBook::show_index_info()
{
    int index;
     
     std::cout << "Type the index you are searching...:" << std::endl;
        std::cin >> index;
    for (int i = 0; i < 5; i++)
    {
            std::cout << info[index][i] << std::endl;
    }
}

int main()
{
    PhoneBook repertory;
    Contact contact;
    int num = 0;  
    std::string cmd;
    
    std::cout << "Welcome to your Phonebook !" << std::endl;
    std::cout << "Type ADD to add a new contact or SEARCH to find one." << std::endl;
    while (1)
    {
        std::cin >> cmd;
        if (cmd == "ADD")
        {
            repertory.get_contact_info(num);
                num += 1;
                if (num == 8)
                    num = 7;
        }
        else if (cmd == "SEARCH")
        {
             contact.show_phonebook(repertory);  
             contact.print_specific_index(repertory);
        }
        else if (cmd == "EXIT")
            return (0);
    }
    return (0);
}
