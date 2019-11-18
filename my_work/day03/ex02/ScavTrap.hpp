#ifndef SCAV_H
# define SCAV_H


# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(std::string name);

	void	challengeNewcomer(std::string const &target);

private:


};


#endif