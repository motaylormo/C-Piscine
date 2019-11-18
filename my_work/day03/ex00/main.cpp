#include "FragTrap.hpp"

int main( void )
{
	std::srand(std::time(0));
	FragTrap a("A");

	while (a.rangedAttack("B"));

	a.takeDamage(50);
	a.beRepaired(10);

	return 0;
}