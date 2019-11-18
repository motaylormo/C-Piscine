#ifndef SCAV_H
# define SCAV_H


# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 50, 20, 15, 3) {}

	void	challengeNewcomer(std::string const &target);

private:


};


#endif