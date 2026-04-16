#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::jacobsthalSequence(int n)
{
	std::vector<int> seq;
	if (n <= 0)
		return seq;
	seq.push_back(0);
	if (n == 1)
		return seq;
	seq.push_back(1);
	while (true)
	{
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		if (next >= n)
			break;
		seq.push_back(next);
	}
	return seq;
}

void PmergeMe::mergeInsertVector(std::vector<int> &vec)
{
	int n = static_cast<int>(vec.size());
	if (n <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler)
		straggler = vec[n - 1];

	for (int i = 0; i + 1 < n - (hasStraggler ? 1 : 0); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::vector<int> larges;
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].second);

	mergeInsertVector(larges);

	std::vector<std::pair<int, int> > sortedPairs;
	{
		std::vector<std::pair<int, int> > tmp = pairs;
		for (size_t i = 0; i < larges.size(); ++i)
		{
			for (size_t j = 0; j < tmp.size(); ++j)
			{
				if (tmp[j].second == larges[i])
				{
					sortedPairs.push_back(tmp[j]);
					tmp.erase(tmp.begin() + j);
					break;
				}
			}
		}
	}

	std::vector<int> main_chain;
	std::vector<int> pend;

	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		main_chain.push_back(sortedPairs[i].second);
		pend.push_back(sortedPairs[i].first);
	}

	if (!pend.empty())
	{
		main_chain.insert(main_chain.begin(), pend[0]);
		pend.erase(pend.begin());
	}

	int pendSize = static_cast<int>(pend.size());
	std::vector<int> jacobsthal = jacobsthalSequence(pendSize + 1);

	std::vector<bool> inserted(pendSize, false);

	std::vector<int> insertionOrder;
	int prev = 0;
	for (size_t ji = 1; ji < jacobsthal.size(); ++ji)
	{
		int jk = jacobsthal[ji];
		if (jk > pendSize)
			jk = pendSize;
		for (int k = jk - 1; k >= prev; --k)
		{
			if (!inserted[k])
			{
				insertionOrder.push_back(k);
				inserted[k] = true;
			}
		}
		prev = jk;
	}
	for (int k = pendSize - 1; k >= 0; --k)
	{
		if (!inserted[k])
			insertionOrder.push_back(k);
	}

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int val = pend[insertionOrder[i]];
		std::vector<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), val);
		main_chain.insert(pos, val);
	}

	if (hasStraggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}

	vec = main_chain;
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	mergeInsertVector(vec);
}


void PmergeMe::mergeInsertDeque(std::deque<int> &deq)
{
	int n = static_cast<int>(deq.size());
	if (n <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler)
		straggler = deq[n - 1];

	for (int i = 0; i + 1 < n - (hasStraggler ? 1 : 0); i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::deque<int> larges;
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].second);

	mergeInsertDeque(larges);

	std::deque<std::pair<int, int> > sortedPairs;
	{
		std::deque<std::pair<int, int> > tmp = pairs;
		for (size_t i = 0; i < larges.size(); ++i)
		{
			for (size_t j = 0; j < tmp.size(); ++j)
			{
				if (tmp[j].second == larges[i])
				{
					sortedPairs.push_back(tmp[j]);
					tmp.erase(tmp.begin() + j);
					break;
				}
			}
		}
	}

	std::deque<int> main_chain;
	std::deque<int> pend;

	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		main_chain.push_back(sortedPairs[i].second);
		pend.push_back(sortedPairs[i].first);
	}

	if (!pend.empty())
	{
		main_chain.push_front(pend[0]);
		pend.pop_front();
	}

	int pendSize = static_cast<int>(pend.size());
	std::vector<int> jacobsthal = jacobsthalSequence(pendSize + 1);

	std::vector<bool> inserted(pendSize, false);
	std::vector<int> insertionOrder;
	int prev = 0;
	for (size_t ji = 1; ji < jacobsthal.size(); ++ji)
	{
		int jk = jacobsthal[ji];
		if (jk > pendSize)
			jk = pendSize;
		for (int k = jk - 1; k >= prev; --k)
		{
			if (!inserted[k])
			{
				insertionOrder.push_back(k);
				inserted[k] = true;
			}
		}
		prev = jk;
	}
	for (int k = pendSize - 1; k >= 0; --k)
	{
		if (!inserted[k])
			insertionOrder.push_back(k);
	}

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int val = pend[insertionOrder[i]];
		std::deque<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), val);
		main_chain.insert(pos, val);
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}

	deq = main_chain;
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	mergeInsertDeque(deq);
}
