/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:58:37 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:58:39 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
  public:
	virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);