#include "FragTrap.hpp"

#define ATTACKS_COUNT 5
std::string	attacks_list[ATTACKS_COUNT] = {
	"fills the air with gnats",
	"creates merge conflicts",
	"starts a flame war on slack",
	"pours plastic forks in their suitcase and calls the police",
	"kidnaps their cat"
};

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::cout << "\t" << this->_name << " attacks " << target << ": "
				<< attacks_list[std::rand() % ATTACKS_COUNT] << "!"
				<< std::endl;
}


bool	FragTrap::rangedAttack(std::string const &target)
{
	if (ClapTrap::rangedAttack(target))
	{
		vaulthunter_dot_exe(target);
		return (true);
	}
	return (false);
}


bool	FragTrap::meleeAttack(std::string const &target)
{
	if (ClapTrap::meleeAttack(target))
	{
		vaulthunter_dot_exe(target);
		return (true);
	}
	return (false);
}