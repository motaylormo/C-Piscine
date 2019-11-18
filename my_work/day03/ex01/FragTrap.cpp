#include "FragTrap.hpp"

// ************************************************************************** //
//		printy stuff
// ************************************************************************** //
# define BOLD		"\e[1m"
# define COLOR_OFF	"\e[0m"
# define CYN		"\e[36m"
# define ON_CYN		"\e[46m"
# define ON_WHT		"\e[47m"

#define PRINT(x) (std::cout << CYN << x << "\e[0m" << std::endl)
#define PRINT_RECEIPT(x) PRINT("FR4G-TP " << this->_name << " " << x << "!")
#define PRINT_ATTACK(x, num) PRINT_RECEIPT("attacks " << x << ", causing " << num << " points of damage")

static void	print_line(std::string str, int n1, int n2)
{
	std::cout << "\t";
	std::cout << BOLD << str << ": " << COLOR_OFF;
	std::cout << n1 << "/" << n2;
	std::cout << "\t";//std::endl;
	std::cout << ON_CYN;
	for (int i = 0; i < n1 / 5; ++i)
		std::cout << " ";
	std::cout << ON_WHT;
	for (int i = n1 / 5; i < n2 / 5; ++i)
		std::cout << " ";
	std::cout << COLOR_OFF << std::endl;
}

void	FragTrap::print_status(void)
{
	print_line("   Hit points", this->_hitPoints, this->_hitPointsMax);
	print_line("Energy points", this->_energyPoints, this->_energyPointsMax);
}

// ************************************************************************** //
//		constructors and destructor
// ************************************************************************** //

FragTrap::FragTrap(std::string name):
	_hitPoints(100),	_hitPointsMax(100),
	_energyPoints(100),	_energyPointsMax(100),
	_level(1),
	_name(name),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5)
{
	PRINT_RECEIPT("created");
}

FragTrap::FragTrap(const FragTrap &ref) {
	*this = ref;
}

FragTrap::~FragTrap(void)
{
	PRINT_RECEIPT("destroyed");
}

// ************************************************************************** //
//		operator overload
// ************************************************************************** //
FragTrap&		FragTrap::operator=(const FragTrap& rhs)
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
bool	FragTrap::enegryToAttack(std::string const &target)
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
	PRINT("\t" << this->_name << " attacks " << target << ": "
			<< attacks_list[std::rand() % ATTACKS_COUNT] << "!");
}

bool	FragTrap::rangedAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " at range", this->_rangedAttackDamage);
	this->vaulthunter_dot_exe(target);
	this->print_status();
	return (true);
}

bool	FragTrap::meleeAttack(std::string const &target)
{
	if (!this->enegryToAttack(target))
		return (false);

	PRINT_ATTACK(target << " in melee", this->_meleeAttackDamage);
	this->vaulthunter_dot_exe(target);
	this->print_status();
	return (true);
}

// ************************************************************************** //
//		point stuff
// ************************************************************************** //
void	FragTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorDamageReduction);
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	PRINT_RECEIPT("takes damage");
	this->print_status();
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_hitPointsMax)
		this->_hitPoints = this->_hitPointsMax;
	PRINT_RECEIPT("is repaired");
	this->print_status();
}