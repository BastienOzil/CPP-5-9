#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Bureaucrat bad("Bad", 0); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Bureaucrat bad("Bad", 151); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Bureaucrat top("Top", 1); top.incrementGrade(); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Bureaucrat bot("Bot", 150); bot.decrementGrade(); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return 0;
}
