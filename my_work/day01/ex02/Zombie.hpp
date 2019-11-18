#include <iostream>

class Zombie {

public:

	typedef Zombie		z;

	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);

	std::string _name;
	std::string _type;

private:

};