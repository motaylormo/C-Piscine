#ifndef FRAG_H
# define FRAG_H


# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

	FragTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 100, 30, 20, 5) {}

	bool	rangedAttack(std::string const &target);
	bool	meleeAttack(std::string const &target);

	void	vaulthunter_dot_exe(std::string const &target);
	
private:


};


#endif