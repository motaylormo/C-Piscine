#include <iostream>

class ScavTrap {

public:

	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &ref);
	ScavTrap& operator=(ScavTrap const &rhs);//	rhs "right hand side"

	bool	rangedAttack(std::string const &target);
	bool	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	challengeNewcomer(std::string const &target);

private:

	int			_hitPoints;
	int			_hitPointsMax;
	int			_energyPoints;
	int			_energyPointsMax;
	int			_level;
	std::string	_name;
	int			_meleeAttackDamage;
	int			_rangedAttackDamage;
	int			_armorDamageReduction;

	bool	enegryToAttack(std::string const &target);
	void	print_status(void);

};