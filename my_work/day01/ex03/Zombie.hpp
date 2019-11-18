#include <iostream>

class Zombie {

public:

	typedef Zombie		z;

	Zombie(void);	// if no name specified, it's a RandomZom™
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);

private:

	std::string _name;
	std::string _type;

};