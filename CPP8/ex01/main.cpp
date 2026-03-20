#include "Span.hpp"

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
}
/*
int	main(int argc, char **argv)
{
	Span	sp = Span(argc);
	int		i;
	int		y;

	if (argc < 2)
		return (0);
	i = 1;
	y = 2;
	while (y <= argc)
	{
		sp.addNumber(*argv[i]);
		i++;
		y++;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}*/
