#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "<" << this->_name <<
				" (" << this->_type <<
				")> Braiiiiiiinnnssss..." << std::endl;
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
Zombie::Zombie(std::string name):
	_name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}