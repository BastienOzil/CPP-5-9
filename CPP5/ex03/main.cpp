#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm *rrf = intern.makeForm("robotomy request", "Bender");
	if (rrf) { boss.signForm(*rrf); boss.executeForm(*rrf); delete rrf; }

	AForm *scf = intern.makeForm("shrubbery creation", "garden");
	if (scf) { boss.signForm(*scf); boss.executeForm(*scf); delete scf; }

	AForm *ppf = intern.makeForm("presidential pardon", "Ford");
	if (ppf) { boss.signForm(*ppf); boss.executeForm(*ppf); delete ppf; }

	AForm *bad = intern.makeForm("coffee request", "Boss");
	(void)bad;

	return 0;
}
