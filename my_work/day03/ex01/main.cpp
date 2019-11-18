#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	std::srand(std::time(0));

//	Frag
	FragTrap a("A");
	while (a.rangedAttack("B"));
	a.takeDamage(50);
	a.beRepaired(10);

//	Scav
	ScavTrap c("C");
	while (c.rangedAttack("D"));
	c.takeDamage(50);
	c.beRepaired(10);

	return 0;
}