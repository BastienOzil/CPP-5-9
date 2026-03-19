#pragma once

template <typename T> typename T::iterator easyfind(T& container, int value)
{
    typename T::integrer it = std::find(container.begin())
    if(it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
