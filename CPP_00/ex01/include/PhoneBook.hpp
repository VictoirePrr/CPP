/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:15 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/30 16:26:20 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>
#include <sstream>

#include "Contact.hpp"

class PhoneBook {
    
    private :
    
        std::string _userInput;
        std::string _repertory[8][5]; 
        
    public :
    
        PhoneBook();
        ~PhoneBook();

        int _numContacts;

        void add_contact(Contact& contact);
        void show_contacts_info();
        void show_index_info();

};


#endif