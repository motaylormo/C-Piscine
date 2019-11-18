#include "ScavTrap.hpp"

// ************************************************************************** //
//		printy stuff
// ************************************************************************** //
# define BOLD		"\e[1m"
# define COLOR_OFF	"\e[0m"
# define GRN		"\e[32m"
# define ON_GRN		"\e[42m"
# define ON_WHT		"\e[47m"

#define PRINT(x) (std::cout << GRN << x << "\e[0m" << std::endl)
#define PRINT_RECEIPT(x) PRINT("FR4G-TP " << this->_name << " " << x << "!")
#define PRINT_ATTACK(x, num) PRINT_RECEIPT("attacks " << x << ", causing " << num << " points of damage")

static void	print_line(std::string str, int n1, int n2)
{
	std::cout << "\t";
	std::cout << BOLD << str << ": " << COLOR_OFF;
	std::cout << n1 << "/" << n2;
	std::cout << "\t";//std::endl;
	std::cout << ON_GRN;
	for (int i = 0; i < n1 / 5; ++i)
		std::cout << " ";
	std::cout << ON_WHT;
	for (int i = n1 / 5; i < n2 / 5; ++i)
		std::cout << " ";
	std::cout << COLOR_OFF << std::endl;
}

void	ScavTrap::print_status(void)
{
	print_line("   Hit points", this->_hitPoints, this->_hitPointsMax);
	print_line("Energy points", this->_energyPoints, this->_energyPointsMax);
}

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

ScavTrap::ScavTrap(std::string name):
	_hitPoints(100),	_hitPointsMax(100),
	_energyPoints(50),	_energyPointsMax(50),
	_level(1),
	_name(name),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3)
{
	PRINT_RECEIPT("created");
}

ScavTrap::ScavTrap(const ScavTrap &ref) {
	*this = ref;
}

ScavTrap::~ScavTrap(void)
{
	PRINT_RECEIPT("destroyed");
}

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
ScavTrap&		ScavTrap::operator=(const ScavTrap& rhs)
{
	this->_hitPoints = rhs._hitPoints;
	this->_hitPointsMax = rhs._hitPointsMax;
	this->_energyPoints = rhs._energyPoints;
	this->_energyPointsMax = rhs._energyPointsMax;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;
	return (*this);
}

// ************************************************************************** //
//		attacks
// ************************************************************************** //
bool	ScavTrap::enegryToAttack(std::string const &target)
{
	if (this->_energyPoints < 25)
	{
		PRINT_RECEIPT("does not have enough energy to attack " << target);
		this->print_status();
		return (false);
	}
	this->_energyPoints -= 25;
	return (true);
}

#define CHALLENGES_COUNT 3
std::string	challenges_list[CHALLENGES_COUNT] = {
	"Come, come, you froward and unable worms!",
	"Go, prick thy face, and over-red thy fear, Thou lily-liver’d boy.",
	"I would challenge you to a battle of wits, but I see you are unarmed!"
};

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	PRINT("\t" << this->_name << " challenges " << target << ": "
			<< "\"" << challenges_list[std::rand() % CHALLENGES_COUNT] << "\"");
}

bool	ScavTrap::rangedAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " at range", this->_rangedAttackDamage);
	this->challengeNewcomer(target);
	this->print_status();
	return (true);
}

bool	ScavTrap::meleeAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " in melee", this->_meleeAttackDamage);
	this->challengeNewcomer(target);
	this->print_status();
	return (true);
}

// ************************************************************************** //
//		point stuff
// ************************************************************************** //
void	ScavTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorDamageReduction);
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	PRINT_RECEIPT("takes damage");
	this->print_status();
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_hitPointsMax)
		this->_hitPoints = this->_hitPointsMax;
	PRINT_RECEIPT("is repaired");
	this->print_status();
}