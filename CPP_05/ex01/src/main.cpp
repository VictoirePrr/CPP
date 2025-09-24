/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:53:29 by victoire          #+#    #+#             */
/*   Updated: 2025/09/24 10:08:03 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"


int main() {
    try {
        std::cout << R "--- Création de John et du TaxForm ---" RESET << std::endl;
        Bureaucrat john("John", 50);       
        Form taxForm("TaxForm", 45, 60);   
        std::cout << john << std::endl;    
        std::cout << taxForm << std::endl; 

        std::cout << R "--- John tente de signer TaxForm ---" RESET << std::endl;
        john.signForm(taxForm);           
        std::cout << taxForm << std::endl; 

        std::cout << R "--- Création d’Alice et nouvelle tentative ---" RESET << std::endl;
        Bureaucrat alice("Alice", 40);    
        alice.signForm(taxForm); 
        std::cout << taxForm << std::endl;

        std::cout << R "--- Tentative de création d’un mauvais formulaire ---" RESET << std::endl;
        Form badForm("BadForm", 0, 170); 
    }
    catch (std::exception& e) {
        std::cerr << R "Exception from BadForm : " RESET << e.what() << std::endl;
    }
    return 0;
}

