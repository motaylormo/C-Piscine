#include "Pony.hpp"

# define FORMAT		"\e[35m"
# define FORMAT_OFF	"\e[0m"

void	Pony::display(void)
{
	std::cout << FORMAT;

	std::cout << this->name << std::endl;

	std::cout << FORMAT_OFF;
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
Pony::Pony(void)
{
	std::cout << FORMAT;

	std::cout << "Pony ctor" << std::endl;
	std::cout << "Name this pony: ";
	std::cin >> this->name;

	std::cout << FORMAT_OFF;
}

Pony::~Pony(void)
{
	std::cout << FORMAT;

	std::cout << "Pony dtor-ed for " << this->name << std::endl;

	std::cout << FORMAT_OFF;
}