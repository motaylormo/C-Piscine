#include <iostream>

class FragTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(const FragTrap &ref);
	FragTrap& operator=(FragTrap const &rhs);//	rhs "right hand side"

	bool	rangedAttack(std::string const &target);
	bool	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

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

	void	vaulthunter_dot_exe(std::string const &target);
	bool	enegryToAttack(std::string const &target);
	void	print_status(void);

};