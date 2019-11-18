#include "Human.hpp"

Brain&		Human::getBrain(void)
{
	return (this->_brain);
}

std::string	Human::identify(void)
{
	return (_brain.identify());
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
Human::Human(void):
	_brain(Brain())
{}

Human::~Human(void){ }