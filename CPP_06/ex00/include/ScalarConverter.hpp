/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:04 by victoire          #+#    #+#             */
/*   Updated: 2025/09/16 16:46:06 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {

        private :

            ScalarConverter();

        public :

            ScalarConverter(const ScalarConverter& other);
            ScalarConverter& operator=(const ScalarConverter& other);
            ~ScalarConverter();

            static void convert(std::string s);

};

#endif // MUST NO BE INSTANSIABLE
