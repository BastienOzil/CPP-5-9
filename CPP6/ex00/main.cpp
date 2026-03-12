/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:08 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:58:10 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Test 1: 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	std::cout << "Test 2: nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	std::cout << "Test 3: 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	return (0);
}
