#include "Form.hpp"

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Form::Form(void){ }

Form::Form(std::string name, int toSign, int toExec):
	_name(name),
	_signed(false),
	_gradeToSign(toSign),
	_gradeToExec(toExec)
{

}

Form::Form(const Form &ref)	{ *this = ref; }

Form::~Form(void){ }

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
Form&	Form::operator=(const Form &rhs)//	rhs "right hand side"
{
	this->_name = rhs._name;
	this->_signed = rhs._signed;
	this->_gradeToSign = rhs._gradeToSign;
	this->_gradeToExec = rhs._gradeToExec;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form &rhs)
{
	os << rhs.getName() << ", " << (rhs.getState() ? "signed" : "unsigned");
	return (os);
}

// ************************************************************************** //
//		throw exception
// ************************************************************************** //
const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

// ************************************************************************** //
//		getters
// ************************************************************************** //
std::string	Form::getName(void) const	{ return (this->_name); }
bool		Form::getState(void) const{ return (this->_signed); }

// ************************************************************************** //
//		methods
// ************************************************************************** //
bool		Form::signForm(Bureaucrat &bur)
{
	if (this->_signed == true)
	{
		std::cout << bur.getName() << " cannot sign " << this->_name
				<< " because form is already signed"<< std::endl;
		return (false);
	}
	if (bur.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << bur.getName() << " signs " << this->_name << std::endl;
		return (true);
	}
	std::cout << bur.getName() << " cannot sign " << this->_name
				<< " because grade is too low"<< std::endl;
	return (false);
}

void		Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}