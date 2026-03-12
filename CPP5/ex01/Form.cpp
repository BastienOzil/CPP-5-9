/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:54:05 by bozil             #+#    #+#             */
/*   Updated: 2026/03/12 10:54:07 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (minimum is 1).");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (maximum is 150).");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form: " << f.getName() << " | signed: " << (f.isSigned() ? "yes" : "no") << " | grade to sign: " << f.getGradeToSign() << " | grade to execute: " << f.getGradeToExecute() << ".";
	return (os);
}
