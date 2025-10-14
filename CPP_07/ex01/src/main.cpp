/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:11:20 by vicperri          #+#    #+#             */
/*   Updated: 2025/10/14 11:44:54 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
	std::cout << "\033[1;36m===== INT ARRAY =====\033[0m" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, printArray<int>);

	std::cout << "\033[1;36m===== DOUBLE ARRAY =====\033[0m" << std::endl;
	double doubleArray[] = {3.14, 2.71, 1.618, 42.0};
	iter(doubleArray, 4, printArray<double>);

	std::cout << "\033[1;36m===== STRING ARRAY =====\033[0m" << std::endl;
	std::string strArray[] = {"I", "am", "vicperri"};
	iter(strArray, 3, printArray<std::string>);

	std::cout << "\033[1;36m===== CHAR ARRAY =====\033[0m" << std::endl;
	char charArray[] = {'A', 'B', 'C', 'D'};
	iter(charArray, 4, printArray<char>);

	std::cout << "\033[1;36m===== CONST ARRAY TESTS =====\033[0m" << std::endl;
	const int constInts[] = {10, 20, 30};
	const std::string constStrs[] = {"I", "am", "const"};

	std::cout << "\033[1;33m-- Const int array --\033[0m" << std::endl;
	iter(constInts, 3, printArray<const int>);

	std::cout << "\033[1;33m-- Const string array --\033[0m" << std::endl;
	iter(constStrs, 3, printArray<const std::string>);

	return 0;
}
