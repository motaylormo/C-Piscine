#include "ScavTrap.hpp"

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name, 100, 50)
{
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
}

// ************************************************************************** //
//		attacks
// ************************************************************************** //
#define CHALLENGES_COUNT 3
std::string	challenges_list[CHALLENGES_COUNT] = {
	"Come, come, you froward and unable worms!",
	"Go, prick thy face, and over-red thy fear, Thou lily-liver’d boy.",
	"I would challenge you to a battle of wits, but I see you are unarmed!"
};

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	std::cout << "\t" << this->_name << " challenges " << target << ": "
				<< "\"" << challenges_list[std::rand() % CHALLENGES_COUNT] << "\""
				<< std::endl;
}
