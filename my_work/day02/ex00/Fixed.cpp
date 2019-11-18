#include "Fixed.hpp"
#include <iostream>

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

//	"A default constructor that initializes the fixed point value to 0."
Fixed::Fixed(void):
	_fixedPointVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//	"A copy constructor."
Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

//	"An assignation operator overload."
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointVal = other.getRawBits();// other._fixedPointVal;
//	this->setRawBits(other.getRawBits());
	return (*this);
}

//	"A destructor."
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ************************************************************************** //
//		member functions
// ************************************************************************** //

//	"A member function that returns the raw value of the fixed point value."
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointVal);
}

//	"A member function that sets the raw value of the fixed point value."
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointVal = raw;
}
