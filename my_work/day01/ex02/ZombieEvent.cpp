#include "ZombieEvent.hpp"
#include <fstream>
#include <climits>

void	ZombieEvent::setZombieType(Zombie *z, std::string type)
{
	z->_type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie *z = new Zombie(name);
	setZombieType(z, "named zombie");
	return (z);
}

/*	randon name	*/
void	random_printable_chars(char *str, int size)
{
	std::ifstream inFile;
	inFile.open("/dev/random");

	inFile.getline(str, size);
	for (int i = 0; i < size; ++i)
		str[i] = ((unsigned int)str[i] % 26) + 'a';
	str[size] = '\0';
}

#define NAMESIZE 20
Zombie*	ZombieEvent::randomChump(void)
{
	char buf[NAMESIZE];
	random_printable_chars(buf, NAMESIZE);

	Zombie *z = newZombie(buf);
	setZombieType(z, "random");
	return (z);
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
ZombieEvent::ZombieEvent(void)
{
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}