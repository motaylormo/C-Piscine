#include "Zombie.hpp"
#include <fstream>
#define NAMESIZE 20

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

// ************************************************************************** //
// 			RandomZom™ ctor
// ************************************************************************** //
static void	random_printable_chars(char *str, int size)
{
	std::ifstream inFile;
	inFile.open("/dev/random");

	inFile.getline(str, size);
	for (int i = 0; i < size; ++i)
		str[i] = ((unsigned int)str[i] % 26) + 'a';
	str[size] = '\0';
}

Zombie::Zombie(void)
{
	char buf[NAMESIZE];
	random_printable_chars(buf, NAMESIZE);
	this->_name = buf;
	this->_type = "RandomZom™";
}