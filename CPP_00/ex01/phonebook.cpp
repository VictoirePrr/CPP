/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:58:50 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:11 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : _numContacts(0), _maxContacts(8), _flag(&_numContacts) {

    std::cout << "Welcome to your Phonebook !" << std::endl;
    while (1)
    {
        Contact newContact;
        std::cout << "Type ADD to add a new contact or SEARCH to find one." << std::endl;
        if (!std::getline(std::cin, _userInput)) {
            if (std::cin.eof()) {
                std::cout << "\nInput ended by EOF (Ctrl+D). Exiting." << std::endl;
                break;
            }
            else {
                std::cerr << "\nInput error occurred. Exiting." << std::endl;
                break;
            }
        }
        if (_userInput.empty()) {
            std::cout << "Empty input." << std::endl;
            continue;
        }
        if ( _userInput == "ADD")
        {
            newContact.get_contact_info();
            add_contact(newContact);
        }
        else if ( _userInput == "SEARCH")
        {
            show_contacts_info();  
            show_index_info();
        }
        else if ( _userInput == "EXIT")
            break;
    }
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_contact(Contact& contact) {
    if (_numContacts >= 8) {
        _flag = const_cast<int*>(&_maxContacts);
        _numContacts = 0;
    }
    _contacts[_numContacts] = contact;
    _numContacts += 1;
}

void print_text(const std::string& text) 
{
    if (text.length() > 10) {
        std::string truncated = text.substr(0, 9) + ".";
        std::cout << std::setw(10) << truncated;
    } else {
        std::cout << std::setw(10) << text;
    }
}

void PhoneBook::show_contacts_info()
{
    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i]._firstName.empty())
            break;
        std::stringstream ss;
        ss << (i + 1);
        print_text(ss.str());
        std::cout << "|";
        print_text(_contacts[i]._firstName);
        std::cout << "|";
        print_text(_contacts[i]._lastName);
        std::cout << "|";
        print_text(_contacts[i]._nickname);
        std::cout << std::endl;
    }
}

void PhoneBook::show_index_info()
{
    std::string input;
    int index;

    std::cout << "Type the index you are searching (1 to " << *_flag << "):" << std::endl;
    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) {
            if (std::cin.eof())
                break;
            else {
                std::cerr << "\nInput error occurred. Exiting." << std::endl;
                break;
            }
        }
        if (input.empty()) {
            std::cout << "Empty input. Please enter a valid index (1 to " << *_flag << "):" << std::endl;
            continue;
        }
        std::istringstream iss(input);
        if (!(iss >> index) || !(iss.eof())) {
            std::cout << "Invalid input. Please enter a valid number (1 to " << *_flag << "):" << std::endl;
            continue;
        }
        index -= 1;
        if (index < 0 || index > *_flag - 1 ) {
            std::cout << "Index does not exist. Please enter a number between 1 and " << *_flag << ": ";
            continue;
        }
        std::cout << "First Name: " << _contacts[index]._firstName << std::endl;
        std::cout << "Last Name: " << _contacts[index]._lastName << std::endl;
        std::cout << "Nickname: " << _contacts[index]._nickname << std::endl;
        std::cout << "PhoneNumber : " << _contacts[index].get_phoneNumber() << std::endl;
        std::cout << "Darkest secret : " << _contacts[index].get_darkestSecret() << std::endl;
        break;
    }
}


