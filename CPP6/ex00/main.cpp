#include "ScalarConverter.hpp"
#include <iostream>

int main(void) {
	std::cout << "Test 1: 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << "Test 2: nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	std::cout << "Test 3: 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;

	return 0;
}
