#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int	main(void)
{
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);

    std::list<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 4);
        std::cout << "Find: " << *it << " on vector" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(values, 2);
        std::cout << "Find: " << *it << " on list" <<std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(values, 42);
        std::cout << "List get: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}