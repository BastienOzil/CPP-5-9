/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:55:57 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:55:58 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern &src)
{
	(void)src;
}
Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}
Intern::~Intern()
{
}

AForm *Intern::makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName,
	const std::string &target) const
{
	struct					FormEntry
	{
		std::string name;
		AForm				*(*create)(const std::string &);
	};

	static const FormEntry	forms[] = {{"shrubbery creation",
			&Intern::makeShrubbery}, {"robotomy request",
			&Intern::makeRobotomy}, {"presidential pardon",
			&Intern::makePardon}};

	static const int		count = 3;

	for (int i = 0; i < count; i++)
	{
		if (forms[i].name == formName)
		{
			AForm			*f = forms[i].create(target);
			std::cout << "Intern creates " << f->getName() << "." << std::endl;
			return (f);
		}
	}
	std::cerr << "Error: unknown form name '" << formName << "'." << std::endl;
	return (NULL);
}
