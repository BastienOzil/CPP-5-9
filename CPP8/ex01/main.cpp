#include "Span.hpp"
#include <cerrno>
#include <cstdlib>
#include <vector>

/*
int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}*/

static int	parseInt(const char *value)
{
	char *end;
	long number;

	errno = 0;
	number = std::strtol(value, &end, 10);
	if (errno != 0 || *end != '\0' || number < INT_MIN || number > INT_MAX)
		throw std::runtime_error("Invalid integer argument");
	return (static_cast<int>(number));
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " <int1> <int2> <int3> ...]" << std::endl;
		return (1);
	}

	try
	{
		std::vector<int> values;
		values.reserve(argc - 1);
		for (int i = 1; i < argc; ++i)
			values.push_back(parseInt(argv[i]));

		Span span(argc - 1);
		span.addNumbers(values.begin(), values.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest : " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}

