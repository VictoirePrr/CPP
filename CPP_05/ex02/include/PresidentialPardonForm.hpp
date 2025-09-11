/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:16:10 by victoire          #+#    #+#             */
/*   Updated: 2025/09/11 12:16:12 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private :

		std::string _target;
		PresidentialPardonForm();

	public:

    	PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);
		void executeAction() const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f);

#endif
