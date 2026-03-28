#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::sort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;
	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());
	sort(left);
	sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(),
		vec.begin());
}
