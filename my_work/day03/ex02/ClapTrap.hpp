#ifndef CLAP_H
# define CLAP_H

#include <iostream>

class ClapTrap {

public:

	ClapTrap(std::string name, int hp, int ep);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &ref);
	ClapTrap& operator=(ClapTrap const &rhs);//	rhs "right hand side"

	bool	rangedAttack(std::string const &target);
	bool	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:

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

#endif