/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:58:50 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/24 17:05:31 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void print_text(const std::string& text) 
{
    if (text.length() > 10) 
        std::cout << text.substr(0, 9) << "." ;
    else 
        std::cout << text;
}

void PhoneBook::get_contact_info(int num, int flag)
{
    (void)flag;
    std::cout << "Enter your first name...:" << std::endl;
    std::cin >> info[num][0];
    std::cout << "Enter your last name...:" << std::endl;  
    std::cin >> info[num][1];
    std::cout << "Enter your nickname...:" << std::endl;
    std::cin >> info[num][2];
    std::cout << "Enter your phone number...:" << std::endl;
    std::cin >> info[num][3];
    std::cout << "Enter your darkest secret...:" << std::endl;
    std::cin >> info[num][4];
}

void PhoneBook::show_contacts_info()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " | ";
        for (int j = 0; j < 5; j++)
        {
            print_text(info[i][j]);
            if (j != 4)
              std::cout << " | ";
        }
        std::cout << std::endl;
        if (info[i + 1][0].empty())
               i = 8; 
    }
}

void PhoneBook::show_index_info(int num, int flag)
{
    int index;

    std::cout << "Type the index you are searching...:" << std::endl;
    while (true)
    {
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer index: ";
        }
        else if (flag == 0 && (index < 0 || index >= num))
                std::cout << "Index does not exist. Please enter a number between 0 and " << (num - 1) << ": ";
        else if (flag == 1 && (index < 0 || index >= 8))
                std::cout << "Index does not exist. Please enter a number between 0 and 7 : ";
        else
            break;
    }
    for (int i = 0; i < 5; i++)
    {
        print_text(info[index][i]);
        std::cout << std::endl;
    }
}

int main()
{
    PhoneBook repertory;
    Contact contact;
    int num = 0;
    int flag = 0;
    std::string cmd;
    
    std::cout << "Welcome to your Phonebook !" << std::endl;
    while (1)
    {
        std::cout << "Type ADD to add a new contact or SEARCH to find one." << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD")
        {
            repertory.get_contact_info(num, flag);
                num += 1;
                if (num >= 8)
                {
                    num = 0;
                    flag = 1;
                }
        }
        else if (cmd == "SEARCH")
        {
             contact.show_phonebook(repertory);  
             contact.print_specific_index(repertory, num, flag);
        }
        else if (cmd == "EXIT")
            return (0);
    }
    return (0);
}
