#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T &value)
{
	std::cout << value << " ";
}

void increment(int &value)
{
	++value;
}

void shout(std::string &value)
{
	value += "!";
}

int main(void)
{
	int numbers[] = {1, 2, 3};
	const int fixed[] = {7, 8, 9};
	std::string words[] = {"Hello", "World"};

	iter(numbers, 3, increment);
	iter(numbers, 3, printElement<int>);
	std::cout << std::endl;

	iter(fixed, 3, printElement<int>);
	std::cout << std::endl;

	iter(words, 2, shout);
	iter(words, 2, printElement<std::string>);
	std::cout << std::endl;

	return (0);
}

