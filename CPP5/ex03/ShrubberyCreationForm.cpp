#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file " << _target << "_shrubbery" << std::endl;
		return;
	}
	file << "        *        " << std::endl;
	file << "       ***       " << std::endl;
	file << "      *****      " << std::endl;
	file << "     *******     " << std::endl;
	file << "    *********    " << std::endl;
	file << "   ***********   " << std::endl;
	file << "        |        " << std::endl;
	file << "        |        " << std::endl;
	file << "     *     *     " << std::endl;
	file << "    ***   ***    " << std::endl;
	file << "   ***** *****   " << std::endl;
	file << "  ************** " << std::endl;
	file << "       |||       " << std::endl;
	file << "       |||       " << std::endl;
	file.close();
}
