
#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Array<int> a1;
	std::cout << "a1.size(): " << a1.size() << std::endl;
	Array<int> a2(5);
	std::cout << "a2.size(): " << a2.size() << std::endl;
	for (unsigned int i = 0; i < a2.size(); ++i)
		std::cout << "a2[" << i << "]: " << a2[i] << std::endl;
	Array<int> a3(a2);
	a3[0] = 42;
	std::cout << "a3[0]: " << a3[0] << ", a2[0]: " << a2[0] << std::endl;
	Array<int> a4;
	a4 = a2;
	a4[1] = 99;
	std::cout << "a4[1]: " << a4[1] << ", a2[1]: " << a2[1] << std::endl;
	try
	{
		std::cout << a2[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	Array<std::string> a5(2);
	a5[0] = "hello";
	a5[1] = "world";
	std::cout << a5[0] << " " << a5[1] << std::endl;
	return (0);
}
