#include <iostream>

class Fixed {

public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &ref);
	Fixed(const int n);
	Fixed(const float n);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	static const Fixed&	max(Fixed const &a, Fixed const &b);
	static const Fixed&	min(Fixed const &a, Fixed const &b);

	Fixed&	operator=(const Fixed& ref);
	/*	arithmetic operators	*/
	Fixed&	operator+(const Fixed& ref);
	Fixed&	operator-(const Fixed& ref);
	Fixed&	operator*(const Fixed& ref);
	Fixed&	operator/(const Fixed& ref);
	/*	increment operators	*/
	Fixed&	operator++(void); //pre
	Fixed&	operator--(void);
	Fixed&	operator++(int);  //post
	Fixed&	operator--(int);
	/*	comparison operators	*/
	bool	operator>(const Fixed& ref);
	bool	operator<(const Fixed& ref);
	bool	operator>=(const Fixed& ref);
	bool	operator<=(const Fixed& ref);
	bool	operator==(const Fixed& ref);
	bool	operator!=(const Fixed& ref);

private:

	int					_fixedPointVal;
	static const int	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& ref);