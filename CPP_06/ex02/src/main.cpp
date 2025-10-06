/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:17:29 by victoire          #+#    #+#             */
/*   Updated: 2025/10/06 14:01:59 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


static void title(const std::string &s) {
	std::cout << "\n\033[1;35m=== " << s << " ===\033[0m\n";
}

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	title("RANDOM INSTANCE GENERATION");
	for (int i = 0; i < 5; i++)
	{
		Base *ptr = generate();
		std::cout << "Test " << i + 1 << ":\n";
		std::cout << "Pointer identification: ";
		identify(ptr);
		std::cout << "Reference identification: ";
		identify(*ptr);
		delete ptr;
	}

	title("MANUAL TESTS");
	{
		Base *a = new A();
		Base *b = new B();
		Base *c = new C();

		std::cout << "\nIdentifying manually created instances:\n";
		std::cout << "A:\n";
		identify(a);
		identify(*a);
		std::cout << "B:\n";
		identify(b);
		identify(*b);
		std::cout << "C:\n";
		identify(c);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}

	title("NULL POINTER SAFETY TEST");
	{
		Base *nullPtr = NULL;
		std::cout << "Trying to identify a null pointer...\n";
		identify(nullPtr);
	}

	std::cout << "\n\033[1;32mAll tests completed successfully!\033[0m\n";
	return 0;
}