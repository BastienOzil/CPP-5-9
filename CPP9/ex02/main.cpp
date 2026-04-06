#include "PmergeMe.hpp"

bool isValidPositiveInteger(const char *str, int &result)
{
	char *endptr;
	long val = std::strtol(str, &endptr, 10);

	if (*endptr != '\0' || val < 0 || val > 2147483647)
		return (false);
	result = static_cast<int>(val);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int> vec_numbers;
	std::deque<int> deq_numbers;

	for (int i = 1; i < argc; ++i)
	{
		int num;
		if (!isValidPositiveInteger(argv[i], num))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		vec_numbers.push_back(num);
		deq_numbers.push_back(num);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec_numbers.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << vec_numbers[i];
	}
	std::cout << std::endl;

	PmergeMe sorter;
	auto start_vec = std::chrono::high_resolution_clock::now();
	sorter.sortVector(vec_numbers);
	auto end_vec = std::chrono::high_resolution_clock::now();

	auto start_deq = std::chrono::high_resolution_clock::now();
	sorter.sortDeque(deq_numbers);
	auto end_deq = std::chrono::high_resolution_clock::now();

	std::cout << "After: ";
	for (size_t i = 0; i < vec_numbers.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << vec_numbers[i];
	}
	std::cout << std::endl;

	double time_vec = std::chrono::duration<double, std::micro>(end_vec - start_vec).count();
	double time_deq = std::chrono::duration<double, std::micro>(end_deq - start_deq).count();

	std::cout << "Time to process a range of " << vec_numbers.size()
		<< " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq_numbers.size()
		<< " elements with std::deque : " << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

	return (0);
}

/*
"Vector" Cache-friendly due to contiguity
"Deque" Enables comparative measurement of different allocation strategies
*/