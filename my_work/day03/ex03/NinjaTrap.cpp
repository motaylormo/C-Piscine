#include "NinjaTrap.hpp"

/*
void	NinjaTrap::ninjaShoebox(ClapTrap &param)
{
	ClapTrap *ptr = &param;

	if (dynamic_cast<FragTrap*>(ptr))
		std::cout << "NinjaTrap for FragTrap " << param.getName() << std::endl;
}
*/


#define PRINT(x) (std::cout << "NinjaTrap for " << x << " " << param.getName() << std::endl)

void	NinjaTrap::ninjaShoebox(FragTrap &param)
{
	PRINT("FragTrap");
}

void	NinjaTrap::ninjaShoebox(ScavTrap &param)
{
	PRINT("ScavTrap");
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &param)
{
	PRINT("NinjaTrap");
}

void	NinjaTrap::ninjaShoebox(ClapTrap &param)
{
	PRINT("ClapTrap");
}