#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn;
		rpn.evaluate(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}

/*
"stack" enforces the natural LIFO order for RPN
Simple interface: push/pop/top (no iteration)
Does not require random access
*/