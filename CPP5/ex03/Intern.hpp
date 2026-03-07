#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm	*makeForm(const std::string &formName, const std::string &target) const;

private:
	static AForm	*makeShrubbery(const std::string &target);
	static AForm	*makeRobotomy(const std::string &target);
	static AForm	*makePardon(const std::string &target);
};

#endif
