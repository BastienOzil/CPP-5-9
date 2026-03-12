/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:55:02 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:55:04 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat b("Bureaucrat", 1);
	ShrubberyCreationForm scf("home");
	b.signForm(scf);
	b.executeForm(scf);
	RobotomyRequestForm rrf("Robot");
	b.signForm(rrf);
	b.executeForm(rrf);
	PresidentialPardonForm ppf("A");
	b.signForm(ppf);
	b.executeForm(ppf);
	PresidentialPardonForm ppf2("B");
	b.executeForm(ppf2);
	Bureaucrat low("Low", 10);
	b.signForm(ppf2);
	low.executeForm(ppf2);
	return (0);
}
