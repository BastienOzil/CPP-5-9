#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high (minimum is 1).";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low (maximum is 150).";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed.";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form: " << f.getName()
	   << " | signed: " << (f.isSigned() ? "yes" : "no")
	   << " | grade to sign: " << f.getGradeToSign()
	   << " | grade to execute: " << f.getGradeToExecute() << ".";
	return os;
}
