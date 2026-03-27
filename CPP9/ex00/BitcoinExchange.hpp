#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
  private:
	std::map<std::string, double> _rates;

	static std::string trim(const std::string &value);
	static bool isLeapYear(int year);
	static bool isValidDate(const std::string &date);
	static bool parseValue(const std::string &valueText, double &value);

	void loadDatabase(const std::string &databasePath);
	bool findRateForDate(const std::string &date, double &rate) const;

  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void processInputFile(const std::string &inputPath) const;
};

#endif