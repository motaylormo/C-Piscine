#include "ScavTrap.hpp"

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
