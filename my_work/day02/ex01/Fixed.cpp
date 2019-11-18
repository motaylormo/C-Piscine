#include "Fixed.hpp"

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

//	"A default constructor that initializes the fixed point value to 0."
Fixed::Fixed(void):
	_fixedPointVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int n):
	_fixedPointVal(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n):
	_fixedPointVal(n * (1 << _fractionalBits))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ************************************************************************** //
//		operator overload
// ************************************************************************** //

Fixed&			Fixed::operator=(const Fixed& other)
{
	this->_fixedPointVal = other._fixedPointVal;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& ref)
{
	os << ref.toFloat();
	return (os);
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

float	Fixed::toFloat(void) const
{
	return (((float)this->_fixedPointVal) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->toFloat());
}