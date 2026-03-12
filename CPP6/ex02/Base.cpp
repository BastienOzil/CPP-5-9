/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:33 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:58:34 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base()
{
}

Base	*generate(void)
{
	static bool	seeded = false;
	int			random;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	random = std::rand() % 3;
	if (random == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}

	std::cout << "Unknown type" << std::endl;
}