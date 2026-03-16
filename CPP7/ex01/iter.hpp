#pragma once

#include <cstddef>

template <typename T, typename Function> void iter(T *add,
	const std::size_t len, Function ft)
{
	for (std::size_t i = 0; i < len; ++i)
		ft(add[i]);
}

template <typename T, typename Function> void iter(const T *add,
	const std::size_t len, Function ft)
{
	for (std::size_t i = 0; i < len; ++i)
		ft(add[i]);
}