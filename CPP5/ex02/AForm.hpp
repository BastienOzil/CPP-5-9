/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:54:31 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:54:33 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

  public:
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};

  protected:
	virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
