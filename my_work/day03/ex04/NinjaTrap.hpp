#ifndef NINJA_H
# define NINJA_H


# include "ClapTrap.hpp"

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {

public:

	NinjaTrap(std::string name) : ClapTrap::ClapTrap(name, 60, 120, 60, 5, 0) {}

	void	ninjaShoebox(FragTrap &param);
	void	ninjaShoebox(ScavTrap &param);
	void	ninjaShoebox(NinjaTrap &param);
	void	ninjaShoebox(ClapTrap &param);

private:


};


#endif