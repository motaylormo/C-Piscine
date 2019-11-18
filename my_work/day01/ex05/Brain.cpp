#include "Brain.hpp"
#include <string>
#include <sstream>

std::string	Brain::identify(void)
{
	std::stringstream	buf;

	buf << this;
	return (buf.str());
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
Brain::Brain(void){ }

Brain::~Brain(void){ }