#include "SuperTrap.hpp"

bool	SuperTrap::rangedAttack(std::string const &target)
{
	return (FragTrap::rangedAttack(target));
}

bool	SuperTrap::meleeAttack(std::string const &target)
{
	return (NinjaTrap::meleeAttack(target));
}