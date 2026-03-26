#pragma once

#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <vector>

class Span
{
  private:
	unsigned int _size;
	std::vector<int> _numbers;

  public:
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
};
