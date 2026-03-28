#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sort(std::vector<int> &vec);
	
};