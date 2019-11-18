#ifndef SUPER_H
# define SUPER_H


# include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"



class SuperTrap : public FragTrap, public NinjaTrap {

public:

//	SuperTrap(std::string name);// : FragTrap::FragTrap(name, FragTrap::_hitPoints, 120, 60, 5, 0) {}

	bool	rangedAttack(std::string const &target);
	bool	meleeAttack(std::string const &target);

private:


};


#endif