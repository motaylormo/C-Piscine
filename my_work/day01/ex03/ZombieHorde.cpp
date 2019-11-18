#include "ZombieHorde.hpp"

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_n; ++i)
		this->_arr[i].announce();
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
ZombieHorde::ZombieHorde(int n):
	_n(n)
{
	this->_arr = new Zombie[n];
}

ZombieHorde::~ZombieHorde(void)
{
	delete[] _arr;
}