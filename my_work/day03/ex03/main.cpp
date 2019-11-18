#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main( void )
{
	std::srand(std::time(0));

//	Frag
	std::cout << std::endl << "Frag" << std::endl;
	FragTrap a("A");
	while (a.rangedAttack("B"))
		a.vaulthunter_dot_exe("B");
	a.takeDamage(50);
	a.beRepaired(10);

//	Scav
	std::cout << std::endl << "Scav" << std::endl;
	ScavTrap c("C");
	while (c.rangedAttack("D"))
		c.challengeNewcomer("D");
	c.takeDamage(50);
	c.beRepaired(10);

//	Ninja
	std::cout << std::endl << "Ninja" << std::endl;
	NinjaTrap e("E");
	while (e.rangedAttack("F"));
	e.takeDamage(50);
	e.beRepaired(10);
	e.ninjaShoebox(a);
	e.ninjaShoebox(c);
	e.ninjaShoebox(e);

	return 0;
}