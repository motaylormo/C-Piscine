#include <iostream>

class Contactbook {

public:

	Contactbook(void);
	~Contactbook(void);

	int			count;
	std::string	field[8][11];

	void	add(void);
	void	search(void);
	void	exit(void);

};