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
int	main(void)
{
	try
	{
		Span big(10000);
		for (int i = 0; i < 10000; ++i)
			big.addNumber(i * 2); // 0, 2, 4, ..., 19998
		std::cout << "Shortest: " << big.shortestSpan() << std::endl; // 2
		std::cout << "Longest : " << big.longestSpan() << std::endl;  // 19998
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
*/
