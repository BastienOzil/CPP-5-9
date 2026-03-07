#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try { Form bad("Bad", 0, 10); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Form bad("Bad", 151, 10); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try
	{
		Bureaucrat low("Low", 100);
		Form f("Contract", 10, 5);
		low.signForm(f);
		Bureaucrat high("High", 5);
		high.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return 0;
}
