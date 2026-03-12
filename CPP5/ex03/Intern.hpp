/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:56:01 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:56:02 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
  public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm *makeForm(const std::string &formName,
		const std::string &target) const;

  private:
	static AForm *makeShrubbery(const std::string &target);
	static AForm *makeRobotomy(const std::string &target);
	static AForm *makePardon(const std::string &target);
};