#include "PmergeMe.hpp"
#include <sys/time.h>

bool isValidPositiveInteger(const char *str, int &result)
{
	if (!str || *str == '\0')
		return (false);
	char *endptr;
	long val = std::strtol(str, &endptr, 10);
	if (*endptr != '\0' || val < 0 || val > 2147483647)
		return (false);
	result = static_cast<int>(val);
	return (true);
}

static double getTimeMicro()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<double>(tv.tv_sec) * 1000000.0
		+ static_cast<double>(tv.tv_usec));
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int> vec_numbers;
	std::deque<int>  deq_numbers;

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

	std::cout << "Before:";
	for (size_t i = 0; i < vec_numbers.size(); ++i)
		std::cout << " " << vec_numbers[i];
	std::cout << std::endl;

	PmergeMe sorter;

	double start_vec = getTimeMicro();
	sorter.sortVector(vec_numbers);
	double end_vec = getTimeMicro();

	double start_deq = getTimeMicro();
	sorter.sortDeque(deq_numbers);
	double end_deq = getTimeMicro();

	std::cout << "After:";
	for (size_t i = 0; i < vec_numbers.size(); ++i)
		std::cout << " " << vec_numbers[i];
	std::cout << std::endl;

	double time_vec = end_vec - start_vec;
	double time_deq = end_deq - start_deq;

	std::cout << "Time to process a range of " << vec_numbers.size()
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq_numbers.size()
		<< " elements with std::deque : "
		<< std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

	return (0);
}
