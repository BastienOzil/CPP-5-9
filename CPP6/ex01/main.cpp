/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:22 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:58:23 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.name = "Test";
	data.value = 42;
	data.score = 98.5;
	std::cout << "Original: " << &data << std::endl;
	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << ptr << std::endl;
	std::cout << "Equal: " << (ptr == &data ? "Yes" : "No") << std::endl;
	std::cout << "Value: " << ptr->value << std::endl;
	return (0);
}
