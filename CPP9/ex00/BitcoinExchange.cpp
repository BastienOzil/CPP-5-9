#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <limits>
#include <sstream>

namespace
{
bool	isDigits(const std::string &text)
{
	if (text.empty())
		return (false);
	for (std::string::size_type i = 0; i < text.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(text[i])))
			return (false);
	}
	return (true);
}
} // namespace

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string &value)
{
	std::string::size_type start = 0;
	while (start < value.size()
		&& std::isspace(static_cast<unsigned char>(value[start])))
		++start;
	std::string::size_type end = value.size();
	while (end > start && std::isspace(static_cast<unsigned char>(value[end
				- 1])))
		--end;
	return (value.substr(start, end - start));
}

bool BitcoinExchange::isLeapYear(int year)
{
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	return (year % 4 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int					year;
	int					month;
	int					day;
	static const int	daysByMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
			31, 30, 31};
	int					maxDay;

	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	std::string yearText = date.substr(0, 4);
	std::string monthText = date.substr(5, 2);
	std::string dayText = date.substr(8, 2);
	if (!isDigits(yearText) || !isDigits(monthText) || !isDigits(dayText))
		return (false);
	year = std::atoi(yearText.c_str());
	month = std::atoi(monthText.c_str());
	day = std::atoi(dayText.c_str());
	if (month < 1 || month > 12)
		return (false);
	if (day < 1)
		return (false);
	maxDay = daysByMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	return (day <= maxDay);
}

bool BitcoinExchange::parseValue(const std::string &valueText, double &value)
{
	char	*endPtr;

	endPtr = NULL;
	value = std::strtod(valueText.c_str(), &endPtr);
	if (endPtr == valueText.c_str() || *endPtr != '\0')
		return (false);
	return (true);
}

void BitcoinExchange::loadDatabase(const std::string &databasePath)
{
	double	rate;

	std::ifstream database(databasePath.c_str());
	if (!database.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	if (!std::getline(database, line))
		throw std::runtime_error("Error: bad database.");
	while (std::getline(database, line))
	{
		if (line.empty())
			continue ;
		std::string::size_type commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue ;
		std::string date = trim(line.substr(0, commaPos));
		std::string rateText = trim(line.substr(commaPos + 1));
		rate = 0.0;
		if (!isValidDate(date) || !parseValue(rateText, rate))
			continue ;
		_rates[date] = rate;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: bad database.");
}

bool BitcoinExchange::findRateForDate(const std::string &date,
	double &rate) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
	{
		rate = it->second;
		return (true);
	}
	if (it == _rates.begin())
		return (false);
	--it;
	rate = it->second;
	return (true);
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const
{
	std::ifstream input(inputPath.c_str());
	if (!input.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	bool firstLine = true;
	while (std::getline(input, line))
	{
		if (line.empty())
			continue ;
		if (firstLine)
		{
			firstLine = false;
			if (trim(line) == "date | value")
				continue ;
		}

		std::string::size_type pipePos = line.find('|');
		if (pipePos == std::string::npos || line.find('|', pipePos
				+ 1) != std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueText = trim(line.substr(pipePos + 1));
		double value = 0.0;

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!parseValue(valueText, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0.0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}

		double rate = 0.0;
		if (!findRateForDate(date, rate))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::cout << date << " => " << value << " = " << (value
			* rate) << std::endl;
	}
}