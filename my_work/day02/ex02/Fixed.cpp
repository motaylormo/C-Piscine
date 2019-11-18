#include "Fixed.hpp"

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

Fixed::Fixed(void):
	_fixedPointVal(0){ }

Fixed::Fixed(const int n):
	_fixedPointVal(n << _fractionalBits){ }

Fixed::Fixed(const float n):
	_fixedPointVal(n * (1 << _fractionalBits)){ }

Fixed::Fixed(const Fixed &ref) {
	*this = ref;
}

Fixed::~Fixed(void) { }

// ************************************************************************** //
//		member functions
// ************************************************************************** //
int		Fixed::getRawBits(void) const {
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointVal = raw;
}

float	Fixed::toFloat(void) const {
	return (((float)this->_fixedPointVal) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->toFloat());
}

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
Fixed&		Fixed::operator=(const Fixed& ref)
{
	this->_fixedPointVal = ref._fixedPointVal;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& ref)
{
	os << ref.toFloat();
	return (os);
}

/*
	arithmetic operators
*/
Fixed&		Fixed::operator-(const Fixed& ref)
{
	this->_fixedPointVal -= ref.getRawBits();
	return (*this);
}

Fixed&		Fixed::operator+(const Fixed& ref)
{
	this->_fixedPointVal += ref.getRawBits();
	return (*this);
}

Fixed&		Fixed::operator/(Fixed const & ref)
{
	this->_fixedPointVal = ((this->_fixedPointVal << _fractionalBits) / ref.getRawBits());
	return (*this);
}

Fixed&		Fixed::operator*(Fixed const & ref)
{
	this->_fixedPointVal = ((long)(this->_fixedPointVal) *
							(long)(ref.getRawBits()) >> this->_fractionalBits);
	return (*this);
}

/*
	increment operators
*/
Fixed&		Fixed::operator++(int) {return (this->operator++());}
Fixed&		Fixed::operator++(void)
{
	this->_fixedPointVal++;
	return (*this);
}

Fixed&		Fixed::operator--(int) {return (this->operator--());}
Fixed&		Fixed::operator--(void)
{
	this->_fixedPointVal--;
	return (*this);
}

/*
	max min
*/
Fixed const&	Fixed::max(Fixed const &a, Fixed const &b) {return ((a.getRawBits() > b.getRawBits()) ? a : b);}
Fixed const&	Fixed::min(Fixed const &a, Fixed const &b) {return ((a.getRawBits() < b.getRawBits()) ? a : b);}

/*
	comparison operators
*/
bool	Fixed::operator>(const Fixed& ref) {return (this->getRawBits() > ref.getRawBits());}
bool	Fixed::operator<(const Fixed& ref) {return (this->getRawBits() < ref.getRawBits());}
bool	Fixed::operator>=(const Fixed& ref) {return (this->getRawBits() >= ref.getRawBits());}
bool	Fixed::operator<=(const Fixed& ref) {return (this->getRawBits() <= ref.getRawBits());}
bool	Fixed::operator==(const Fixed& ref) {return (this->getRawBits() == ref.getRawBits());}
bool	Fixed::operator!=(const Fixed& ref) {return (this->getRawBits() != ref.getRawBits());}