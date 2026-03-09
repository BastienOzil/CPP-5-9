#pragma once

#include <string>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(const std::string& literal);
};
