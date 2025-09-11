/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:16:16 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 12:17:57 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime> 

class RobotomyRequestForm : public AForm {

	private :

		std::string _target;
		RobotomyRequestForm();

	public:

    	RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		void executeAction() const;
		std::string getTarget() const;
};
 
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& f);

