#ifndef FRAG_H
# define FRAG_H


# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 100, 30, 20, 5) {}

	void	vaulthunter_dot_exe(std::string const &target);
	
private:


};


#endif