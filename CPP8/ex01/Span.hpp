#pragma once

#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <stdexcept>
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
	template <typename InputIterator> void addNumbers(InputIterator first,
		InputIterator last);
	int shortestSpan() const;
	int longestSpan() const;
};

template <typename InputIterator> 
void Span::addNumbers(InputIterator first, InputIterator last)
{
	std::vector<int> values;
	for (; first != last; ++first)
		values.push_back(*first);
	if (_numbers.size() + values.size() > _size)
		throw std::runtime_error("Span is full");
	_numbers.insert(_numbers.end(), values.begin(), values.end());
}
