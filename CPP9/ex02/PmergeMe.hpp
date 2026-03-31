#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <iomanip>

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
	void mergeVector(std::vector<int> &vec);
	void mergeDeque(std::deque<int> &deq);
};