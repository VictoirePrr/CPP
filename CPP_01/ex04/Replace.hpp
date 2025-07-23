/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:16:37 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/23 14:24:47 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <fstream>

class Replace{
    
    public :
    Replace(std::string& filename, std::string s1, std::string s2);
    ~Replace();
    
};

#endif