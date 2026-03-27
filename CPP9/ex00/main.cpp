#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream file(argv[1]);
	if (argc == 2)
	{
		if (file.is_open())
		{
			std::cout << "File found" << std::endl;

			BitcoinExchange btc;
			return (1);
		}
		else
		{
			std::cerr << "Error: Is not a valid file name" << std::endl;
			return (0);
		}
	}
	else
	{
		std::cout << "Usage: ./btc <file name>" << std::endl;
	}

	file.close();
	return (0);
}