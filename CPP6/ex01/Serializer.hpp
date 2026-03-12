/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:29 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:58:30 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

struct		Data
{
	std::string name;
	int		value;
	double	score;
};

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};