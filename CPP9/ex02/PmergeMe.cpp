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


void PmergeMe::mergeVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> unpaired;

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	if (vec.size() % 2 == 1)
		unpaired.push_back(vec[vec.size() - 1]);

	std::vector<int> main_chain;
	std::vector<int> pend;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	mergeVector(main_chain);

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), pend[i]
		);
		main_chain.insert(pos, pend[i]);
	}

	if (!unpaired.empty())
	{
		std::vector<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), unpaired[0]
		);
		main_chain.insert(pos, unpaired[0]);
	}

	vec = main_chain;
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	mergeVector(vec);
}


void PmergeMe::mergeDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> unpaired;

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	if (deq.size() % 2 == 1)
		unpaired.push_back(deq[deq.size() - 1]);

	std::deque<int> main_chain;
	std::deque<int> pend;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main_chain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	mergeDeque(main_chain);

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::deque<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), pend[i]
		);
		main_chain.insert(pos, pend[i]);
	}

	if (!unpaired.empty())
	{
		std::deque<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), unpaired[0]
		);
		main_chain.insert(pos, unpaired[0]);
	}

	deq = main_chain;
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	mergeDeque(deq);
}
