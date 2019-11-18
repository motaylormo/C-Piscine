#include <iostream>

class Fixed {


public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &ref);
	Fixed(const int n);
	Fixed(const float n);

	Fixed&		operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;


private:

	int					_fixedPointVal;
	static const int	_fractionalBits = 8;

};


std::ostream&	operator<<(std::ostream& os, const Fixed& ref);