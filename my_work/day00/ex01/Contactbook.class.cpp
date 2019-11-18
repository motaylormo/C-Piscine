#include "Contactbook.class.hpp"
#include <stdlib.h>	//	for exit()
#include <string>	//	for str.resize

Contactbook::Contactbook(void)
{
	this->count = 0;
	return ;
}

Contactbook::~Contactbook(void)
{
//	std::cout << "destructor called" << std::endl;
	return ;
}

/*
**	ADD COMMAND
*/
static std::string	field_name[] = {
	"first name",
	"last name",
	"nickname",
	"login",
	"postal address",
	"email address",
	"phone number",
	"birthday date",
	"favorite meal",
	"underwear color",
	"darkest secret"
};

void	Contactbook::add(void)
{
	if (this->count == 8)
	{
		std::cout << "Full, cannot add any more contacts." << std::endl;
		return ;
	}
	for (int i = 0; i < 11; ++i)
	{
		std::cout << "\t" << field_name[i] << ": ";
		std::cin >> this->field[this->count][i];
	}
	this->count += 1;
}

/*
**	SEARCH COMMAND
*/
static void	print10(std::string str)
{
	int len = str.length();
	std::string cpy = str;

	if (len > 10)
	{
		cpy.resize(9);
		cpy.resize(10, '.');
	}
	else
		cpy.resize(10, ' ');
	std::cout << cpy;
}
static void	search_line(int i, std::string line[11])
{
	std::cout << i;
	std::cout << " | ";
	print10(line[0]);
	std::cout << " | ";
	print10(line[1]);
	std::cout << " | ";
	print10(line[2]);
	std::cout << std::endl;
}
void	Contactbook::search(void)
{
	for (int i = 0; i < this->count; ++i)
	{
		search_line(i, this->field[i]);
	}
}

/*
**	EXIT COMMAND
*/
void	Contactbook::exit(void)
{
	std::exit(0);
}