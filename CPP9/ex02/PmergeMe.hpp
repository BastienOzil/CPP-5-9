#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sortVector(std::vector<int> &vec);
	void sortDeque(std::deque<int> &deq);

  private:
	void mergeInsertVector(std::vector<int> &vec);
	void mergeInsertDeque(std::deque<int> &deq);

	std::vector<int> jacobsthalSequence(int n);
};
