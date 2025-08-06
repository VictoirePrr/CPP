/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:45:35 by vicperri          #+#    #+#             */
/*   Updated: 2025/08/06 15:26:07 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define Contact_HPP

#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>

class Contact {

    private :

        std::string _phoneNumber;
        std::string _darkestSecret;

    public :
    
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        
        void get_contact_info();
        std::string get_phoneNumber();
        std::string get_darkestSecret();
        
};

void getNonEmptyInput(const std::string& message, std::string& target);

#endif