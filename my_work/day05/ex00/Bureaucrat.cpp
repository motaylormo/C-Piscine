#include "Bureaucrat.hpp"

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Bureaucrat::Bureaucrat(void){ }

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)	{ *this = ref; }

Bureaucrat::~Bureaucrat(void){ }

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs)//	rhs "right hand side"
{
	this->_name = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

// ************************************************************************** //
//		throw exception
// ************************************************************************** //
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

// ************************************************************************** //
//		getters
// ************************************************************************** //
std::string	Bureaucrat::getName(void) const	{ return (this->_name); }
int			Bureaucrat::getGrade(void) const{ return (this->_grade); }


// ************************************************************************** //
//		incr, decr
// ************************************************************************** //
void	Bureaucrat::increment(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrement(void)
{
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}