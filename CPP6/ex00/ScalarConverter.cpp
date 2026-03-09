#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

enum LiteralType {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

static bool isChar(const std::string& literal) {
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isInt(const std::string& literal) {
	if (literal.empty())
		return false;
	
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	
	if (i >= literal.length())
		return false;
	
	while (i < literal.length()) {
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

static bool isFloat(const std::string& literal) {
	if (literal.length() < 2)
		return false;
	
	if (literal[literal.length() - 1] != 'f')
		return false;
	
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	
	std::string without_f = literal.substr(0, literal.length() - 1);
	
	size_t i = 0;
	if (without_f[i] == '+' || without_f[i] == '-')
		i++;
	
	bool hasDot = false;
	bool hasDigit = false;
	
	while (i < without_f.length()) {
		if (without_f[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (isdigit(without_f[i])) {
			hasDigit = true;
		} else {
			return false;
		}
		i++;
	}
	
	return hasDot && hasDigit;
}

static bool isDouble(const std::string& literal) {
	if (literal.empty())
		return false;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	
	bool hasDot = false;
	bool hasDigit = false;
	
	while (i < literal.length()) {
		if (literal[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (isdigit(literal[i])) {
			hasDigit = true;
		} else {
			return false;
		}
		i++;
	}
	
	return hasDot && hasDigit;
}

static LiteralType detectType(const std::string& literal) {
	if (isChar(literal))
		return TYPE_CHAR;
	if (isInt(literal))
		return TYPE_INT;
	if (isFloat(literal))
		return TYPE_FLOAT;
	if (isDouble(literal))
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

static void printChar(char c) {
	std::cout << "char: ";
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void printInt(int n) {
	std::cout << "int: " << n << std::endl;
}

static void printFloat(float f) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void convertFromChar(char c) {
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

static void convertFromInt(int n) {
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(n));
	
	printInt(n);
	printFloat(static_cast<float>(n));
	printDouble(static_cast<double>(n));
}

static void convertFromFloat(float f) {
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(f));
	
	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		printInt(static_cast<int>(f));
	
	printFloat(f);
	printDouble(static_cast<double>(f));
}

static void convertFromDouble(double d) {
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(d));
	
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		printInt(static_cast<int>(d));
	
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::convert(const std::string& literal) {
	LiteralType type = detectType(literal);
	
	switch (type) {
		case TYPE_CHAR: {
			char c = literal[1];
			convertFromChar(c);
			break;
		}
		case TYPE_INT: {
			errno = 0;
			long l = strtol(literal.c_str(), NULL, 10);
			if (errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max()) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			} else {
				convertFromInt(static_cast<int>(l));
			}
			break;
		}
		case TYPE_FLOAT: {
			float f = strtof(literal.c_str(), NULL);
			convertFromFloat(f);
			break;
		}
		case TYPE_DOUBLE: {
			double d = strtod(literal.c_str(), NULL);
			convertFromDouble(d);
			break;
		}
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}
