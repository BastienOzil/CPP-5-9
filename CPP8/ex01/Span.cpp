#include "Span.hpp"

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _size)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enought numbers to find a span!");
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span ::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enought numbers to find a span!");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
