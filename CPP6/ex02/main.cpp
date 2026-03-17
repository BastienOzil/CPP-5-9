/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:41 by bozil             #+#    #+#             */
/*   Updated: 2026/03/17 10:52:20 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main(void)
{
	Base	*p1 = NULL;
	delete	p1;
	Base	*p2 = NULL;
	delete	p2;
	Base	*p3 = NULL;
	delete	p3;

	p1 = generate();
	identify(p1);
	identify(*p1);
	std::cout << std::endl;
	p2 = generate();
	identify(p2);
	identify(*p2);
	std::cout << std::endl;
	p3 = generate();
	identify(p3);
	identify(*p3);
	return (0);
}
