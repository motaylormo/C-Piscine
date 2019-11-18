#include "Zombie.hpp"

class ZombieHorde {

public:

	typedef ZombieHorde		z;

	ZombieHorde(int n);
	~ZombieHorde(void);

	void	announce(void);

private:

	int		_n;
	Zombie	*_arr;

};