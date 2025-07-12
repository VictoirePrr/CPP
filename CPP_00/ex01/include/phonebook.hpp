/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:15 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/11 20:01:21 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iomanip>
#include <iostream>
#include <cctype>


class PhoneBook {
private:
     std::string info[8][5]; 
    
public:
    void get_contact_info(std::string argv); 
    void show_contacts_info();
};

class Contact {   
public:
void show_phonebook(PhoneBook& contact) {
    contact.show_contacts_info();
    }
};

#endif