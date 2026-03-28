#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void evaluate(const std::string &expression);
};