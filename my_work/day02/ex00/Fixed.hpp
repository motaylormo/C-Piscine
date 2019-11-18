class Fixed {


public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &ref);
	Fixed&	operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);


private:

	int					_fixedPointVal;
	static const int	_fractionalBits = 8;

};