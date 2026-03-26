#include "MutantStack.hpp"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	value;

	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <value1> <value2> ... <valueN>" << std::endl;
		return (1);
	}
	MutantStack<int> mstack;
	for (int i = 1; i < argc; ++i)
	{
		value = atoi(argv[i]);
		mstack.push(value);
		std::cout << "Pushed: " << value << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

/*
int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}*/