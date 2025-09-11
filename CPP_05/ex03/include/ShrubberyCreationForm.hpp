/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:16:21 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 12:18:04 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

	private :

		std::string _target;
		ShrubberyCreationForm();

	public:

    	ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);
		void executeAction() const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& f);

