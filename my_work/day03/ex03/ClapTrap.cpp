#include "ClapTrap.hpp"

// ************************************************************************** //
//		printy stuff
// ************************************************************************** //
#define ON_WHT		"\e[47m"
#define ON_BLK		"\e[100m"

#define RECEIPT(x) (std::cout << "FR4G-TP " << this->_name << " " << x << "!" << std::endl)
#define PRINT_ATTACK(x, num) RECEIPT("attacks " << x << ", causing " << num << " points of damage")

static void	print_line(std::string str, int n1, int n2)
{
	std::cout << "\t";
	std::cout << "\e[1m" << str << ": " << "\e[22m";
	std::cout << n1 << "/" << n2;
	std::cout << "\t";
	std::cout << ON_WHT;
	for (int i = 0; i < n1 / 5; ++i)
		std::cout << " ";
	std::cout << ON_BLK;
	for (int i = n1 / 5; i < n2 / 5; ++i)
		std::cout << " ";
	std::cout << "\e[49m" << std::endl;
}

void	ClapTrap::print_status(void)
{
	print_line("   Hit points", this->_hitPoints, this->_hitPointsMax);
	print_line("Energy points", this->_energyPoints, this->_energyPointsMax);
}

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //
ClapTrap::ClapTrap(std::string name, int hp, int ep, int melee, int range, int armor):
	_hitPoints(hp),		_hitPointsMax(hp),
	_energyPoints(ep),	_energyPointsMax(ep),
	_level(1),
	_name(name),
	_meleeAttackDamage(melee),
	_rangedAttackDamage(range),
	_armorDamageReduction(armor)
{
	RECEIPT("created");
}

ClapTrap::ClapTrap(const ClapTrap &ref) {
	*this = ref;
}

ClapTrap::~ClapTrap(void)
{
	RECEIPT("destroyed");
}

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
ClapTrap&		ClapTrap::operator=(const ClapTrap& rhs)
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
bool	ClapTrap::enegryToAttack(std::string const &target)
{
	if (this->_energyPoints < 25)
	{
		RECEIPT("does not have enough energy to attack " << target);
		this->print_status();
		return (false);
	}
	this->_energyPoints -= 25;
	return (true);
}

bool	ClapTrap::rangedAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " at range", this->_rangedAttackDamage);
	this->print_status();
	return (true);
}

bool	ClapTrap::meleeAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " in melee", this->_meleeAttackDamage);
	this->print_status();
	return (true);
}

// ************************************************************************** //
//		point stuff
// ************************************************************************** //
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorDamageReduction);
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	RECEIPT("takes damage");
	this->print_status();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_hitPointsMax)
		this->_hitPoints = this->_hitPointsMax;
	RECEIPT("is repaired");
	this->print_status();
}

// ************************************************************************** //
//		getters and setters
// ************************************************************************** //
std::string	ClapTrap::getName(void)
{
	return (this->_name);
}