/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:39:54 by victoire          #+#    #+#             */
/*   Updated: 2025/10/07 10:26:02 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data original;
    original.length = 5;
    original.text = "Hello World !";
    original.value = 57.42;

    std::cout << BM << "=== Original Data ===" << RESET << std::endl;
    std::cout << "Address: " << &original << std::endl;
    std::cout << "length: " << original.length << std::endl;
    std::cout << "text: " << original.text << std::endl;
    std::cout << "value: " << original.value << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\nSerialized uintptr_t: " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << BM << "\n=== Restored Data ===" << RESET << std::endl;
    std::cout << "Address: " << restored << std::endl;
    std::cout << "length: " << restored->length << std::endl;
    std::cout << "text: " << restored->text << std::endl;
    std::cout << "value: " << restored->value << std::endl;

    return 0;
}