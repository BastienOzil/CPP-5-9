#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
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

	return 0;
}
