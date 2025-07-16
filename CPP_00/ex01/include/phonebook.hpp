/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:15 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/16 11:07:55 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>


class PhoneBook {
private:
     std::string info[8][5]; 
    
public:
    void get_contact_info(int num); 
    void show_contacts_info();
    void show_index_info(int num);
};

class Contact {   
public:
void show_phonebook(PhoneBook& contact) {
    contact.show_contacts_info();
    }
void print_specific_index(PhoneBook& contact, int num) {
    contact.show_index_info(num);
    }
};

#endif