/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:56:05 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:56:06 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	intern;
	AForm	*rrf;
		delete rrf;
	AForm	*scf;
		delete scf;
	AForm	*ppf;
		delete ppf;
	AForm	*bad;

	Bureaucrat boss("Boss", 1);
	rrf = intern.makeForm("robotomy request", "Robot");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
	}
	scf = intern.makeForm("shrubbery creation", "garden");
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
	}
	ppf = intern.makeForm("presidential pardon", "A");
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
	}
	bad = intern.makeForm("coffee request", "Boss");
	(void)bad;
	return (0);
}
