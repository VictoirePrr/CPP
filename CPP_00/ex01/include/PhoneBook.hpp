/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:00:15 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/31 17:11:14 by victoire         ###   ########lyon.fr   */
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
        std::string _repertory[8][4]; 
        
    public :
    
        PhoneBook();
        ~PhoneBook();

        int _numContacts;
        const int _maxContacts;
        int *_flag;

        void add_contact(Contact& contact);
        void show_contacts_info();
        void show_index_info();

};


#endif