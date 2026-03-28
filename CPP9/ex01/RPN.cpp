#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        try
        {
            std::istringstream converter(token);
            int value;
            char leftover;

            if (!(converter >> value) || (converter >> leftover))
                throw std::runtime_error("not a number");
            _stack.push(value);
            continue;
        }
        catch (const std::exception &)
        {
        }

        if (token.length() != 1)
            throw std::runtime_error("Error: invalid token '" + token + "'.");

        char op = token[0];
        if (op != '+' && op != '-' && op != '*' && op != '/')
            throw std::runtime_error("Error: invalid token '" + token + "'.");
        if (_stack.size() < 2)
            throw std::runtime_error("Error: insufficient operands.");

        int b = _stack.top(); _stack.pop();
        int a = _stack.top(); _stack.pop();
        int result;

        switch (op)
        {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            default:
                if (b == 0)
                    throw std::runtime_error("Error: division by zero.");
                result = a / b;
                break;
        }
        _stack.push(result);
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: too many operands.");

    std::cout << _stack.top() << std::endl;
}

