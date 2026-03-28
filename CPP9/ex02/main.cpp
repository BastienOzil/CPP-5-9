#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return (1);
	}

	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		numbers.push_back(atoi(argv[i]));
	}

	PmergeMe sorter;
	sorter.sort(numbers);

	std::cout << "Sorted numbers: ";
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}
